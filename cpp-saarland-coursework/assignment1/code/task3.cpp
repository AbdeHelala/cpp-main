#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

// Compute Hamming distance between two strings of equal length
int hamming_distance(const std::string& a, const std::string& b) {
    int dist = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++dist;
    }
    return dist;
}

// Process a single line of input
void process_line(const std::vector<std::string>& strings, int n, const std::string& k) {
    int size = static_cast<int>(strings.size());
    if (n < 1 || n > size) {
        std::cout << "\n";
        return;
    }

    const std::string& target = strings[n - 1];
    std::vector<int> distances;

    // Calculate Hamming distances (excluding the target itself)
    for (int i = 0; i < size; ++i) {
        if (i == n - 1) continue;
        distances.push_back(hamming_distance(target, strings[i]));
    }

    if (distances.empty()) {
        std::cout << "\n";
        return;
    }

    // Compute min, max, mean, and median
    int minDist = *std::min_element(distances.begin(), distances.end());
    int maxDist = *std::max_element(distances.begin(), distances.end());
    double meanDist = std::accumulate(distances.begin(), distances.end(), 0.0) / distances.size();

    std::sort(distances.begin(), distances.end());
    double medianDist;
    size_t mid = distances.size() / 2;
    if (distances.size() % 2 == 0)
        medianDist = (distances[mid - 1] + distances[mid]) / 2.0;
    else
        medianDist = distances[mid];

    // Count occurrences of substring k in all strings
    int countK = 0;
    for (const auto& s : strings) {
        for (size_t pos = 0; pos + k.size() <= s.size(); ++pos) {
            if (s.substr(pos, k.size()) == k)
                ++countK;
        }
    }

    // Output results
    std::cout << minDist << ' ' << maxDist << ' ' << meanDist << ' ' << medianDist << ' ' << countK << '\n';
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <k>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::string k = argv[2];

    std::string inputLine;
    while (std::getline(std::cin, inputLine)) {
        std::istringstream stream(inputLine);
        std::vector<std::string> strings;
        std::string word;
        while (stream >> word)
            strings.push_back(word);

        process_line(strings, n, k);
    }

    return 0;
}