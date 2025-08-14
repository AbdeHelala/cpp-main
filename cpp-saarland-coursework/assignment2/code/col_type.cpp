#include "col_type.hpp"
#include <string>

// TEMPLATE CONSTRUCTOR
template <typename ValueType>
ColType::ColType(const ValueType& value)
    : container(std::make_unique<DataType<ValueType>>(value)) {}

// COPY CONSTRUCTOR
ColType::ColType(const ColType& other)
    : container(other.container->clone()) {}

// COPY ASSIGNMENT
ColType& ColType::operator=(const ColType& other) {
    if (this != &other) {
        container = other.container->clone();
    }
    return *this;
}

// EQUALITY
bool ColType::operator==(const ColType& other) const {
    return *container == *other.container;
}

// LESS THAN
bool ColType::operator<(const ColType& other) const {
    return *container < *other.container;
}

// TEMPLATE clone() IMPLEMENTATION
template <typename T>
std::unique_ptr<GenericDataType> DataType<T>::clone() const {
    return std::make_unique<DataType<T>>(value);
}

// Explicit template instantiations (needed for linker)
template ColType::ColType<int>(const int&);
template ColType::ColType<std::string>(const std::string&);
template std::unique_ptr<GenericDataType> DataType<int>::clone() const;
template std::unique_ptr<GenericDataType> DataType<std::string>::clone() const;
