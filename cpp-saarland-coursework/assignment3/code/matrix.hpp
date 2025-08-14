#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cassert>
#include <initializer_list>
#include <memory>
#include <ostream>
#include <algorithm>

template <typename T> class col_reverse_iterator;
template <typename T> class const_col_reverse_iterator;
template <typename T> class diag_iterator;
template <typename T> class const_diag_iterator;

template <class T>
class Matrix {
 public:
  class Invalid {};

  Matrix(std::size_t nrows, std::size_t ncols) : Matrix(nrows, ncols, T()) {}

  Matrix(std::size_t nrows, std::size_t ncols, T init)
      : nrows_(nrows), ncols_(ncols),
        data_(std::make_unique<T[]>(nrows * ncols)) {
    if (nrows == 0 || ncols == 0) throw Invalid{};
    std::fill(data_.get(), data_.get() + nrows * ncols, init);
  }

  Matrix(std::initializer_list<std::initializer_list<T>> elements)
      : nrows_(elements.size()), ncols_(0), data_() {
    if (elements.size() == 0 || elements.begin()->size() == 0) throw Invalid{};
    ncols_ = elements.begin()->size();
    data_ = std::make_unique<T[]>(nrows_ * ncols_);
    std::size_t i = 0;
    for (auto& row : elements) {
      if (row.size() != ncols_) throw Invalid{};
      for (auto& val : row) data_[i++] = val;
    }
  }

  Matrix(const Matrix& m)
      : nrows_(m.nrows()), ncols_(m.ncols()),
        data_(std::make_unique<T[]>(m.nrows() * m.ncols())) {
    std::copy(m.data_.get(), m.data_.get() + (nrows_ * ncols_), data_.get());
  }

  Matrix& operator=(const Matrix& m) {
    if (this == &m) return *this;
    if (nrows_ * ncols_ < m.nrows() * m.ncols()) {
      data_ = std::make_unique<T[]>(m.nrows() * m.ncols());
    }
    nrows_ = m.nrows();
    ncols_ = m.ncols();
    std::copy(m.data_.get(), m.data_.get() + (nrows_ * ncols_), data_.get());
    return *this;
  }

  T& operator()(std::size_t i, std::size_t j) {
    assert(i < nrows_ && j < ncols_);
    return data_[i * ncols_ + j];
  }

  T operator()(std::size_t i, std::size_t j) const {
    assert(i < nrows_ && j < ncols_);
    return data_[i * ncols_ + j];
  }

  std::size_t nrows() const { return nrows_; }
  std::size_t ncols() const { return ncols_; }

  col_reverse_iterator<T> col_rbegin(std::size_t col_num);
  col_reverse_iterator<T> col_rend(std::size_t col_num);
  const_col_reverse_iterator<T> col_rbegin(std::size_t col_num) const;
  const_col_reverse_iterator<T> col_rend(std::size_t col_num) const;

  diag_iterator<T> diag_begin();
  diag_iterator<T> diag_end();
  const_diag_iterator<T> diag_begin() const;
  const_diag_iterator<T> diag_end() const;

 private:
  std::size_t nrows_;
  std::size_t ncols_;
  std::unique_ptr<T[]> data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
  for (std::size_t i = 0; i < m.nrows(); ++i) {
    for (std::size_t j = 0; j < m.ncols(); ++j) {
      os << m(i, j);
      if (j < m.ncols() - 1) os << " ";
    }
    os << "\n";
  }
  return os;
}

#endif  // MATRIX_HPP
