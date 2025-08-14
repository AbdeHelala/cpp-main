#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "matrix.hpp"
#include <sstream>
#include <iterator>

// Bron–Kerbosch recursive function for finding all maximal cliques in a graph
void bron_kerbosch(const std::set<int>& R, const std::set<int>& P, const std::set<int>& X,
                   const Matrix<int>& adj, std::vector<std::set<int>>& cliques) {
    if (P.empty() && X.empty()) {
        cliques.push_back(R); // Found a maximal clique
        return;
    }

    std::set<int> P_copy = P;  // Safe copy for iteration
    for (int v : P_copy) {
        // Find neighbors of v
        std::set<int> N_v;
        for (size_t i = 0; i < adj.ncols(); ++i) {
            if (adj(v, i) == 1) {
                N_v.insert(i);
            }
        }

        // Grow the clique
        std::set<int> R_next = R;
        R_next.insert(v);

        // Restrict candidates to neighbors of v
        std::set<int> P_next, X_next;
        std::set_intersection(P.begin(), P.end(), N_v.begin(), N_v.end(),
                              std::inserter(P_next, P_next.begin()));
        std::set_intersection(X.begin(), X.end(), N_v.begin(), N_v.end(),
                              std::inserter(X_next, X_next.begin()));

        bron_kerbosch(R_next, P_next, X_next, adj, cliques);

        // Move v from P to X
        const_cast<std::set<int>&>(P).erase(v);
        const_cast<std::set<int>&>(X).insert(v);
    }
}

int main(int argc, const char* argv[]) {
    // Read adjacency matrix from standard input
    std::vector<std::vector<int>> rows;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::vector<int> row((std::istream_iterator<int>(iss)),
                             std::istream_iterator<int>());
        if (!row.empty())
            rows.push_back(row);
    }

    // Validate matrix
    if (rows.empty() || rows.size() != rows[0].size()) {
        std::cerr << "Input must be a square adjacency matrix.\n";
        return 1;
    }

    // Convert input to Matrix<int>
    size_t n = rows.size();
    Matrix<int> adj(n, n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            adj(i, j) = rows[i][j];

    // Initialize Bron–Kerbosch sets
    std::set<int> R, P, X;
    for (size_t i = 0; i < adj.nrows(); ++i)
        P.insert(i);

    // Run Bron–Kerbosch
    std::vector<std::set<int>> cliques;
    bron_kerbosch(R, P, X, adj, cliques);

    // Output cliques
    for (const auto& clique : cliques) {
        std::cout << "{";
        for (auto it = clique.begin(); it != clique.end(); ++it) {
            if (it != clique.begin()) std::cout << ", ";
            std::cout << *it;
        }
        std::cout << "}\n";
    }

    return 0;
}
