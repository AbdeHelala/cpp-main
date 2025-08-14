#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>

// Helper: sum of decimal digits
long digitSum(long x) {
    x = std::abs(x);
    long s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

// Third quartile (75th percentile), simple index 3*n/4
double thirdQuartile(std::vector<double> v) {
    int n = v.size();
    if (n <= 1) throw std::runtime_error("Iq");
    std::sort(v.begin(), v.end());
    int idx = (3 * n) / 4;
    return v[idx];
}

// n-th smallest (1-based). Returns either the number as string or "In"
std::string nthSmallest(std::vector<double> v, int n) {
    std::sort(v.begin(), v.end());
    if (n < 1 || n > (int)v.size()) return "In";
    double x = v[n-1];
    std::ostringstream oss;
    oss << x;
    return oss.str();
}

// m-th largest (1-based from largest). Returns number or "Im"
std::string mthLargest(std::vector<double> v, int m) {
    std::sort(v.begin(), v.end());
    int sz = v.size();
    if (m < 1 || m > sz) return "Im";
    double x = v[sz - m];
    std::ostringstream oss;
    oss << x;
    return oss.str();
}

// Kaprekar test (correct for small numbers)
bool isKaprekar(unsigned long n) {
    if (n == 1) return true;
    unsigned long sq = n * n;
    std::string s = std::to_string(sq);
    for (int i = 1; i < (int)s.size(); ++i) {
        unsigned long left = std::stoul(s.substr(0, i));
        unsigned long right = std::stoul(s.substr(i));
        if (right > 0 && left + right == n) return true;
    }
    return false;
}

// Lychrel test (stub: always false)
bool isLychrel(unsigned long n) {
    // Not implemented; always returns false
    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <m>\n";
        return 1;
    }
    int n = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);

    std::vector<std::string> lines;
    std::string raw;
    while (std::getline(std::cin, raw)) {
        if (!raw.empty()) lines.push_back(raw);
    }

    std::vector<unsigned long> allNums;

    for (auto &ln : lines) {
        std::istringstream iss(ln);
        std::vector<double> nums;
        double x;
        while (iss >> x) {
            nums.push_back(x);
            allNums.push_back((unsigned long)std::llround(x));
        }
        double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
        long ds = digitSum((long)sum);

        std::string q3;
        try {
            double q = thirdQuartile(nums);
            std::ostringstream o; o << q;
            q3 = o.str();
        } catch (std::runtime_error&) {
            q3 = "Iq";
        }

        std::string nth = nthSmallest(nums, n);
        std::string mth = mthLargest(nums, m);

        std::cout 
            << sum << " "
            << ds  << " "
            << q3  << " "
            << nth << " "
            << mth
            << "\n";
    }

    // Kaprekar line
    bool anyK = false;
    for (auto &v : allNums) {
        if (isKaprekar(v)) {
            if (anyK) std::cout << " ";
            std::cout << v;
            anyK = true;
        }
    }
    std::cout << "\n";

    // Lychrel line (empty because stub returns false)
    bool anyL = false;
    for (auto &v : allNums) {
        if (isLychrel(v)) {
            if (anyL) std::cout << " ";
            std::cout << v;
            anyL = true;
        }
    }
    std::cout << "\n";

    return 0;
}