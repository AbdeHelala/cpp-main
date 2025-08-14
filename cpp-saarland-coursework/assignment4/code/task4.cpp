#include <iostream>
#include <vector>
#include "bloom_filter.hpp"

int main() {
  BloomFilter<int, 128> filter({1, 2, 3, 4, 5}, 3);

  std::cout << "Contains 3? " << filter.contains(3) << "\n"; // Likely true
  std::cout << "Contains 10? " << filter.contains(10) << "\n"; // Likely false

  std::vector<int> positives = {1, 2, 3};
  std::vector<int> negatives = {100, 200, 300, 10, 20};

  double fpr = filter.false_positive_rate(positives.begin(), positives.end(),
                                          negatives.begin(), negatives.end());
  std::cout << "False positive rate: " << fpr << "\n";

  std::cout << "Approx size: " << filter.approx_size() << "\n";

  std::cout << "Space ratio (5 elems): " << filter.space_ratio(5) << "\n";

  return 0;
}
