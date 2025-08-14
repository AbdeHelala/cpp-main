#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <bitset>
#include <cmath>
#include <cstdint>
#include <initializer_list>
#include <iterator>

#include "murmurhash.hpp"

template <typename Key>
struct BloomHash {
  std::size_t operator()(Key key, unsigned int seed) const {
    return murmur3_32(reinterpret_cast<const uint8_t*>(&key), sizeof(Key), seed);
  }
};

template <typename Key, unsigned int m, typename Hash = BloomHash<Key>>
class BloomFilter {
 public:
  explicit BloomFilter(unsigned int num_hashes)
      : k_(num_hashes), data_() {}

  BloomFilter(std::initializer_list<Key> init, unsigned int num_hashes)
      : BloomFilter(num_hashes) {
    for (const auto& key : init) {
      insert(key);
    }
  }

  template <typename It>
  BloomFilter(It first, It last, unsigned int num_hashes)
      : BloomFilter(num_hashes) {
    for (auto it = first; it != last; ++it) {
      insert(*it);
    }
  }

  bool insert(const Key& key) {
    bool already_present = true;
    Hash hasher;
    for (unsigned int i = 0; i < k_; ++i) {
      std::size_t pos = hasher(key, i) % m;
      if (!data_.test(pos)) {
        already_present = false;
        data_.set(pos);
      }
    }
    return !already_present;
  }

  bool contains(const Key& key) const {
    Hash hasher;
    for (unsigned int i = 0; i < k_; ++i) {
      std::size_t pos = hasher(key, i) % m;
      if (!data_.test(pos)) return false;
    }
    return true;
  }

  uint64_t approx_size() const {
    int X = data_.count(); // bits set to 1
    if (X == 0 || X == m) return 0;
    double est = -static_cast<double>(m) / k_ * std::log(1.0 - static_cast<double>(X) / m);
    return static_cast<uint64_t>(std::round(est));
  }

  template <typename It>
  double false_positive_rate(It positive_begin, It positive_end,
                             It negative_begin, It negative_end) const {
    int false_positives = 0, negatives = 0;
    for (auto it = negative_begin; it != negative_end; ++it) {
      ++negatives;
      if (contains(*it)) {
        ++false_positives;
      }
    }
    if (negatives == 0) return 0.0;
    return static_cast<double>(false_positives) / negatives;
  }

  double space_ratio(uint64_t num_elements) const {
    // Ideal space in bits = -n * ln(p) / (ln(2)^2)
    // Approximate space ratio: m / ideal_bits
    if (num_elements == 0) return 1.0;
    double ideal = num_elements * std::log(2.0) * k_;
    return m / ideal;
  }

 private:
  std::bitset<m> data_;
  unsigned int k_;
};

#endif  // BLOOM_FILTER_HPP
