#include "dataframe.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

// Default constructor
Dataframe::Dataframe() = default;

std::size_t Dataframe::nrows() const {
    return data.empty() ? 0 : data.front().size();
}

std::size_t Dataframe::ncols() const {
    return data.size();
}

bool Dataframe::has_rownames() const {
    return !rownames.empty();
}

bool Dataframe::has_colnames() const {
    return !colnames.empty();
}

void Dataframe::set_colnames(const std::vector<std::string>& cnames) {
    if (cnames.size() != ncols()) throw Invalid{};
    if (utils::contains_duplicate(cnames)) throw Invalid{};
    colnames = cnames;
}

void Dataframe::set_rownames(const std::vector<std::string>& rnames) {
    if (rnames.size() != nrows()) throw Invalid{};
    if (utils::contains_duplicate(rnames)) throw Invalid{};
    rownames = rnames;
}

void Dataframe::clear_colnames() {
    colnames.clear();
}

void Dataframe::clear_rownames() {
    rownames.clear();
}

void Dataframe::remove_column(const size_t i) {
    if (i >= ncols()) throw Invalid{};
    auto it = data.begin();
    std::advance(it, i);
    data.erase(it);
    if (!colnames.empty()) colnames.erase(colnames.begin() + i);
}

void Dataframe::remove_column(const std::string& c) {
    auto it = std::find(colnames.begin(), colnames.end(), c);
    if (it == colnames.end()) throw Invalid{};
    remove_column(std::distance(colnames.begin(), it));
}

std::ostream& operator<<(std::ostream& os, const Dataframe& df) {
    if (df.has_colnames()) {
        if (df.has_rownames()) os << "\t";
        for (const auto& name : df.colnames) os << name << "\t";
        os << "\n";
    }

    auto nrows = df.nrows();
    for (size_t i = 0; i < nrows; ++i) {
        if (df.has_rownames()) os << df.rownames[i] << "\t";
        for (const auto& col : df.data) os << col[i].get() << "\t";
        os << "\n";
    }
    return os;
}

void Dataframe::swap_columns(const size_t i, const size_t j) {
    if (i >= ncols() || j >= ncols()) throw Invalid{};
    std::swap(*std::next(data.begin(), i), *std::next(data.begin(), j));
    if (!colnames.empty()) std::swap(colnames[i], colnames[j]);
}

void Dataframe::swap_columns(const std::string& i, const std::string& j) {
    auto it_i = std::find(colnames.begin(), colnames.end(), i);
    auto it_j = std::find(colnames.begin(), colnames.end(), j);
    if (it_i == colnames.end() || it_j == colnames.end()) throw Invalid{};
    swap_columns(std::distance(colnames.begin(), it_i), std::distance(colnames.begin(), it_j));
}

void Dataframe::order_by(size_t index) {
    if (index >= ncols()) throw Invalid{};
    data.sort([index](const std::vector<ColType>& a, const std::vector<ColType>& b) {
        return a[index] < b[index];
    });
}

void Dataframe::order_by(const std::string& c) {
    auto it = std::find(colnames.begin(), colnames.end(), c);
    if (it == colnames.end()) throw Invalid{};
    size_t col_index = std::distance(colnames.begin(), it);

    data.sort([col_index](const std::vector<ColType>& a, const std::vector<ColType>& b) {
        return a[col_index] < b[col_index];
    });
}

bool Dataframe::operator==(const Dataframe& other) const {
    return data == other.data && colnames == other.colnames && rownames == other.rownames;
}

bool Dataframe::operator!=(const Dataframe& other) const {
    return !(*this == other);
}

template<typename T>
void Dataframe::add_column(const std::vector<T>& col_values) {
    if (!data.empty() && col_values.size() != data.front().size()) {
        throw Invalid{};
    }

    std::vector<ColType> new_column;
    for (const auto& val : col_values) {
        new_column.emplace_back(ColType(val));
    }

    data.push_back(std::move(new_column));
}


template<typename T>
T Dataframe::get(const size_t i, const size_t j) const {
    if (i >= nrows() || j >= ncols()) throw Invalid{};
    auto it = std::next(data.begin(), j);
    return get_type_<T>((*it)[i]);
}

template<typename T>
T& Dataframe::get(const size_t i, const size_t j) {
    if (i >= nrows() || j >= ncols()) throw Invalid{};
    auto it = std::next(data.begin(), j);
    return get_type_<T>((*it)[i]);
}

template<typename T>
T Dataframe::get(const std::string& r, const std::string& c) const {
    auto it_row = std::find(rownames.begin(), rownames.end(), r);
    auto it_col = std::find(colnames.begin(), colnames.end(), c);
    if (it_row == rownames.end() || it_col == colnames.end()) throw Invalid{};
    return get<T>(std::distance(rownames.begin(), it_row), std::distance(colnames.begin(), it_col));
}

template<typename T>
T& Dataframe::get(const std::string& r, const std::string& c) {
    auto it_row = std::find(rownames.begin(), rownames.end(), r);
    auto it_col = std::find(colnames.begin(), colnames.end(), c);
    if (it_row == rownames.end() || it_col == colnames.end()) throw Invalid{};
    return get<T>(std::distance(rownames.begin(), it_row), std::distance(colnames.begin(), it_col));
}

template<typename Fun>
void Dataframe::apply(const size_t i, Fun l) {
    if (i >= ncols()) throw Invalid{};
    for (auto& val : *std::next(data.begin(), i)) {
        get_type_<first_argument_t<Fun>>(val) = l(get_type_<first_argument_t<Fun>>(val));
    }
}

template<typename Fun>
void Dataframe::apply(const std::string& c, Fun l) {
    auto it = std::find(colnames.begin(), colnames.end(), c);
    if (it == colnames.end()) throw Invalid{};
    apply(std::distance(colnames.begin(), it), l);
}




template int Dataframe::get<int>(size_t, size_t) const;
template int& Dataframe::get<int>(size_t, size_t);
template std::string Dataframe::get<std::string>(size_t, size_t) const;
template std::string& Dataframe::get<std::string>(size_t, size_t);
template int Dataframe::get<int>(const std::string&, const std::string&) const;
template int& Dataframe::get<int>(const std::string&, const std::string&);
template std::string Dataframe::get<std::string>(const std::string&, const std::string&) const;
template std::string& Dataframe::get<std::string>(const std::string&, const std::string&);
template void Dataframe::apply<std::function<int(int&)>>(const size_t, std::function<int(int&)>);
template void Dataframe::apply<std::function<std::string(std::string&)>>(const size_t, std::function<std::string(std::string&)>);
template void Dataframe::add_column<int>(const std::vector<int>&);
template void Dataframe::add_column<std::string>(const std::vector<std::string>&);

