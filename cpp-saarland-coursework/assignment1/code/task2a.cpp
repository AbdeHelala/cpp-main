#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.reserve(50);

  for (auto i = 0; i < 50; ++i) {
    v.push_back(i);
  }

  for (int i = int(v.size()) - 1; i >= 0; --i) {
    std::cout << i << ": " << v[i] << "\n";
} // 

  return 0;
} 