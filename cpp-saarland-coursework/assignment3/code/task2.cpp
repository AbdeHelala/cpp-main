#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

// Format a double with up to `dec` decimals, trimming trailing zeros
string fmt(double x, int dec) {
    ostringstream oss;
    oss << fixed << setprecision(dec) << x;
    string s = oss.str();
    if (s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    return s;
}

// Compute mean
double mean(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// Compute sample standard deviation
double sample_sd(const vector<double>& v, double m) {
    double sum = 0;
    for (double x : v) sum += (x - m)*(x - m);
    return sqrt(sum / (v.size() - 1));
}

// Apply log2(|x|+1) to each element
void log2_scale(vector<double>& v) {
    for (auto& x : v) x = log2(fabs(x) + 1);
}

// Print top N elements of a log2-scaled vector
void print_top(const vector<double>& v, size_t N) {
    vector<double> tmp = v;
    size_t cnt = min(N, tmp.size());
    partial_sort(tmp.begin(), tmp.begin() + cnt, tmp.end(), greater<>());
    for (size_t i = 0; i < cnt; ++i) {
        if (i) cout << ", ";
        cout << fmt(tmp[i], 2);
    }
    cout << "\n";
}

// Pooled-variance two-sample t-statistic
double pooled_t(double m1, double m2,
                double s1, double s2,
                size_t n1, size_t n2) {
    double num = (n1-1)*s1*s1 + (n2-1)*s2*s2;
    double den = n1 + n2 - 2;
    double sp = sqrt(num/den);
    double se = sp * sqrt(1.0/n1 + 1.0/n2);
    return (m1 - m2) / se;
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Invalid number of arguments.\n";
        return 1;
    }
    unsigned n, m, s, k;
    double p;
    try {
        n = stoul(argv[1]);
        m = stoul(argv[2]);
        s = stoul(argv[3]);
        p = stod(argv[4]);
        k = stoul(argv[5]);
    } catch (...) {
        cerr << "Invalid argument types.\n";
        return 1;
    }
    if (!n || !m || !k || p <= 0.0 || p >= 1.0) {
        cerr << "Invalid argument values.\n";
        return 1;
    }

    // 3 significant digits for means/SD/t-statistics
    cout << setprecision(3);

    // --- V1 ---
    mt19937_64 gen1(s);
    negative_binomial_distribution<int> dist1(k, p);
    vector<double> V1(n);
    generate(V1.begin(), V1.end(), [&]{ return dist1(gen1); });
    double m1 = mean(V1), sd1 = sample_sd(V1, m1);
    cout << "V1 Mean: " << fmt(m1, 2) << "\n"
         << "V1 Sample standard deviation: " << fmt(sd1, 2) << "\n";
    vector<double> L1 = V1;
    log2_scale(L1);
    cout << "V1 Top " << min<size_t>(10, L1.size()) << " elements: ";
    print_top(L1, 5);

    // --- V2 ---
    mt19937_64 gen2(s * 2);
    negative_binomial_distribution<int> dist2(k, p);
    vector<double> V2(m);
    generate(V2.begin(), V2.end(), [&]{ return dist2(gen2); });
    double m2 = mean(V2), sd2 = sample_sd(V2, m2);
    cout << "V2 Mean: " << fmt(m2, 2) << "\n"
         << "V2 Sample standard deviation: " << fmt(sd2, 2) << "\n";
    vector<double> L2 = V2;
    log2_scale(L2);
    cout << "V2 Top " << min<size_t>(10, L2.size()) << " elements: ";
    print_top(L2, 8);

    // --- t-tests ---
    cout << "\nComparing V1 and V2...\n"
         << "Unscaled t-statistic: " << fixed << setprecision(3)
         << pooled_t(m1, m2, sd1, sd2, n, m) << "\n";
    double m1l = mean(L1), sd1l = sample_sd(L1, m1l);
    double m2l = mean(L2), sd2l = sample_sd(L2, m2l);
    cout << "Comparing log2 scaled V1 and V2...\n"
         << "Scaled t-statistic: " << fixed << setprecision(3)
         << pooled_t(m1l, m2l, sd1l, sd2l, n, m) << "\n"
         << "Total degrees of freedom: " << (n + m - 2) << "\n\n";

    // --- Shuffle & multiply, then round before sort ---
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 1);
    mt19937_64 gen3(s * 7);
    shuffle(idx.begin(), idx.end(), gen3);

    vector<double> M(n);
    for (size_t i = 0; i < n; ++i) {
        double raw = idx[i] * L1[i];
        // round each product to 2 decimals
        M[i] = round(raw * 100.0) / 100.0;
    }

    vector<double> ev, od;
    for (double x : M) {
        if (static_cast<int>(round(x)) % 2 == 0) ev.push_back(x);
        else od.push_back(x);
    }
    sort(ev.begin(), ev.end(), greater<>());
    sort(od.begin(), od.end());

    cout << "Sorted vector: ";
    bool first = true;
    for (double x : ev) {
        if (!first) cout << ", ";
        cout << fmt(x, 2);
        first = false;
    }
    for (double x : od) {
        if (!first) cout << ", ";
        cout << fmt(x, 2);
        first = false;
    }
    cout << "\n";

    return 0;
}
