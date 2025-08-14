#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

// Compute statistics for a given set of strings
void computeStatistics(const std::vector<std::string>& strings, int n, const std::string& k) {
    if (n < 1 || n > (int)strings.size()) {
        std::cout << "\n";
        return;
    }
    const std::string& ref = strings[n-1];

    std::vector<int> distances;
    for (int i = 0; i < (int)strings.size(); ++i) {
        if (i == n - 1) continue;
        int dist = 0;
        for (size_t j = 0; j < ref.size(); ++j)
            if (ref[j] != strings[i][j]) dist++;
        distances.push_back(dist);
    }

    if (distances.empty()) {
        std::cout << "\n";
        return;
    }

    int minDist = *std::min_element(distances.begin(), distances.end());
    int maxDist = *std::max_element(distances.begin(), distances.end());
    double meanDist = std::accumulate(distances.begin(), distances.end(), 0.0) / distances.size();

    std::sort(distances.begin(), distances.end());
    double medianDist = distances.size() % 2 ?
        distances[distances.size()/2] :
        (distances[distances.size()/2 - 1] + distances[distances.size()/2]) / 2.0;

    int countK = 0;
    for (const auto& str : strings)
        for (size_t pos = 0; pos + k.size() <= str.size(); ++pos)
            if (str.substr(pos, k.size()) == k) countK++;

    std::cout << minDist << ' ' << maxDist << ' ' << meanDist << ' ' << medianDist << ' ' << countK << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <k>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::string k = argv[2];

    std::vector<std::vector<std::string>> matrix;
    std::string input;

    // Read matrix from input
    while (std::getline(std::cin, input)) {
        std::istringstream ss(input);
        std::vector<std::string> row;
        std::string word;
        while (ss >> word) row.push_back(word);
        if (!row.empty())
            matrix.push_back(row);
    }

    int size = matrix.size();
    if (size == 0) return 0;

    // Rows
    for (const auto& row : matrix)
        computeStatistics(row, n, k);

    // Columns
    for (int col = 0; col < size; ++col) {
        std::vector<std::string> column;
        for (int row = 0; row < size; ++row)
            column.push_back(matrix[row][col]);
        computeStatistics(column, n, k);
    }

    // Main diagonal
    std::vector<std::string> diagonal;
    for (int i = 0; i < size; ++i)
        diagonal.push_back(matrix[i][i]);
    computeStatistics(diagonal, n, k);

    // Upper triangle including diagonal
    std::vector<std::string> upperTriangle;
    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            upperTriangle.push_back(matrix[i][j]);
    computeStatistics(upperTriangle, n, k);

    return 0;
}