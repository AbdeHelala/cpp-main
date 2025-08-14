#include "munkres_algorithm.hpp"
#include <vector>
#include <limits>
#include <algorithm>

using std::size_t;

Matrix<int> run_munkres_algorithm(Matrix<int> c) {
    const size_t n = c.nrows();
    Matrix<int> mask(n, n, 0);
    std::vector<bool> rowCover(n, false), colCover(n, false);

    // Step 1: Row reduction
    for (size_t i = 0; i < n; ++i) {
        int minVal = c(i, 0);
        for (size_t j = 1; j < n; ++j)
            minVal = std::min(minVal, c(i, j));
        for (size_t j = 0; j < n; ++j)
            c(i, j) -= minVal;
    }

    // Step 2: Column reduction
    for (size_t j = 0; j < n; ++j) {
        int minVal = c(0, j);
        for (size_t i = 1; i < n; ++i)
            minVal = std::min(minVal, c(i, j));
        for (size_t i = 0; i < n; ++i)
            c(i, j) -= minVal;
    }

    // Step 3: Star zeros
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (c(i, j) == 0 && !rowCover[i] && !colCover[j]) {
                mask(i, j) = 1;
                rowCover[i] = true;
                colCover[j] = true;
            }
        }
    }
    std::fill(rowCover.begin(), rowCover.end(), false);
    std::fill(colCover.begin(), colCover.end(), false);

    auto count_stars = [&]() {
        int count = 0;
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                if (mask(i, j) == 1)
                    colCover[j] = true;
        for (bool c : colCover) count += c;
        return count;
    };

    while (count_stars() < n) {
        bool done = false;
        size_t z0_row = 0, z0_col = 0;
        while (!done) {
            bool found = false;
            for (size_t i = 0; i < n && !found; ++i) {
                if (rowCover[i]) continue;
                for (size_t j = 0; j < n; ++j) {
                    if (!colCover[j] && c(i, j) == 0) {
                        mask(i, j) = 2;

                        bool has_star = false;
                        size_t j_star = 0;
                        for (size_t jj = 0; jj < n; ++jj) {
                            if (mask(i, jj) == 1) {
                                j_star = jj;
                                has_star = true;
                                break;
                            }
                        }

                        if (!has_star) {
                            z0_row = i;
                            z0_col = j;
                            done = true;
                        } else {
                            rowCover[i] = true;
                            colCover[j_star] = false;
                        }
                        found = true;
                        break;
                    }
                }
            }
            if (!found) break;
        }

        if (done) {
            std::vector<std::pair<size_t, size_t>> path;
            path.emplace_back(z0_row, z0_col);
            bool done_path = false;
            while (!done_path) {
                size_t r = 0;
                for (; r < n; ++r) {
                    if (mask(r, path.back().second) == 1) break;
                }
                if (r == n) {
                    done_path = true;
                } else {
                    path.emplace_back(r, path.back().second);
                    size_t c = 0;
                    for (; c < n; ++c) {
                        if (mask(path.back().first, c) == 2) break;
                    }
                    path.emplace_back(path.back().first, c);
                }
            }
            for (auto [r, c] : path) {
                if (mask(r, c) == 1) mask(r, c) = 0;
                else if (mask(r, c) == 2) mask(r, c) = 1;
            }
            std::fill(rowCover.begin(), rowCover.end(), false);
            std::fill(colCover.begin(), colCover.end(), false);
            for (size_t i = 0; i < n; ++i)
                for (size_t j = 0; j < n; ++j)
                    if (mask(i, j) == 2) mask(i, j) = 0;
        } else {
            int min_uncovered = std::numeric_limits<int>::max();
            for (size_t i = 0; i < n; ++i) {
                if (!rowCover[i]) {
                    for (size_t j = 0; j < n; ++j) {
                        if (!colCover[j])
                            min_uncovered = std::min(min_uncovered, c(i, j));
                    }
                }
            }
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < n; ++j) {
                    if (rowCover[i]) c(i, j) += min_uncovered;
                    if (!colCover[j]) c(i, j) -= min_uncovered;
                }
            }
        }
    }

    Matrix<int> result(n, n, 0);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            if (mask(i, j) == 1)
                result(i, j) = 1;

    return result;
}
