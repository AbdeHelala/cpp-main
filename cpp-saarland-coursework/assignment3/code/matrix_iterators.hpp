#ifndef MATRIX_ITERATORS_HPP
#define MATRIX_ITERATORS_HPP

#include "matrix.hpp"
#include <iterator>

template <typename T>
class col_reverse_iterator {
 public:
  using value_type = T;
  using reference = T&;

  col_reverse_iterator(Matrix<T>* matrix, std::size_t row, std::size_t col)
      : matrix_(matrix), row_(row), col_(col) {}

  reference operator*() { return (*matrix_)(row_, col_); }

  col_reverse_iterator& operator++() {
    --row_;
    return *this;
  }

  bool operator==(const col_reverse_iterator& other) const {
    return row_ == other.row_ && col_ == other.col_;
  }

  bool operator!=(const col_reverse_iterator& other) const {
    return !(*this == other);
  }

 private:
  Matrix<T>* matrix_;
  std::size_t row_;
  std::size_t col_;
};

template <typename T>
class const_col_reverse_iterator {
 public:
  using value_type = T;
  using reference = const T&;

  const_col_reverse_iterator(const Matrix<T>* matrix, std::size_t row, std::size_t col)
      : matrix_(matrix), row_(row), col_(col) {}

  reference operator*() const { return (*matrix_)(row_, col_); }

  const_col_reverse_iterator& operator++() {
    --row_;
    return *this;
  }

  bool operator==(const const_col_reverse_iterator& other) const {
    return row_ == other.row_ && col_ == other.col_;
  }

  bool operator!=(const const_col_reverse_iterator& other) const {
    return !(*this == other);
  }

 private:
  const Matrix<T>* matrix_;
  std::size_t row_;
  std::size_t col_;
};

template <typename T>
class diag_iterator {
 public:
  using value_type = T;
  using reference = T&;

  diag_iterator(Matrix<T>* matrix, std::size_t index)
      : matrix_(matrix), index_(index) {}

  reference operator*() { return (*matrix_)(index_, index_); }

  diag_iterator& operator++() {
    ++index_;
    return *this;
  }

  bool operator==(const diag_iterator& other) const {
    return index_ == other.index_;
  }

  bool operator!=(const diag_iterator& other) const {
    return !(*this == other);
  }

 private:
  Matrix<T>* matrix_;
  std::size_t index_;
};

template <typename T>
class const_diag_iterator {
 public:
  using value_type = T;
  using reference = const T&;

  const_diag_iterator(const Matrix<T>* matrix, std::size_t index)
      : matrix_(matrix), index_(index) {}

  reference operator*() const { return (*matrix_)(index_, index_); }

  const_diag_iterator& operator++() {
    ++index_;
    return *this;
  }

  bool operator==(const const_diag_iterator& other) const {
    return index_ == other.index_;
  }

  bool operator!=(const const_diag_iterator& other) const {
    return !(*this == other);
  }

 private:
  const Matrix<T>* matrix_;
  std::size_t index_;
};

// Definitions

template <typename T>
col_reverse_iterator<T> Matrix<T>::col_rbegin(std::size_t col_num) {
  return col_reverse_iterator<T>(this, nrows_ - 1, col_num);
}

template <typename T>
col_reverse_iterator<T> Matrix<T>::col_rend(std::size_t col_num) {
  return col_reverse_iterator<T>(this, static_cast<std::size_t>(-1), col_num);
}

template <typename T>
const_col_reverse_iterator<T> Matrix<T>::col_rbegin(std::size_t col_num) const {
  return const_col_reverse_iterator<T>(this, nrows_ - 1, col_num);
}

template <typename T>
const_col_reverse_iterator<T> Matrix<T>::col_rend(std::size_t col_num) const {
  return const_col_reverse_iterator<T>(this, static_cast<std::size_t>(-1), col_num);
}

template <typename T>
diag_iterator<T> Matrix<T>::diag_begin() {
  if (nrows_ != ncols_) throw Invalid{};
  return diag_iterator<T>(this, 0);
}

template <typename T>
diag_iterator<T> Matrix<T>::diag_end() {
  if (nrows_ != ncols_) throw Invalid{};
  return diag_iterator<T>(this, nrows_);
}

template <typename T>
const_diag_iterator<T> Matrix<T>::diag_begin() const {
  if (nrows_ != ncols_) throw Invalid{};
  return const_diag_iterator<T>(this, 0);
}

template <typename T>
const_diag_iterator<T> Matrix<T>::diag_end() const {
  if (nrows_ != ncols_) throw Invalid{};
  return const_diag_iterator<T>(this, nrows_);
}

#endif  // MATRIX_ITERATORS_HPP
