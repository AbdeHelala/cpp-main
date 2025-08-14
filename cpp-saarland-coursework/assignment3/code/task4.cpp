#include "matrix.hpp"
#include "matrix_iterators.hpp"

#include <iostream>

int main() {
  Matrix<int> m{{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

  std::cout << "Diagonal: ";
  for (auto it = m.diag_begin(); it != m.diag_end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  std::cout << "Reverse column 0: ";
  for (auto it = m.col_rbegin(0); it != m.col_rend(0); ++it)
    std::cout << *it << " ";
  std::cout << "\n";

  return 0;
}
