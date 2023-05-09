#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename E>
class Array {
 public:
  // Orthodox Canonical Form
  Array() : _size(0), _data(NULL) {}
  Array(const Array& a) throw(std::bad_alloc)
      : _size(a._size), _data(new E[a._size]) {
    for (unsigned int i = 0; i < _size; i++) _data[i] = a._data[i];
  }
  Array& operator=(const Array& a) {
    if (this != &a) {
      delete[] _data;
      _size = a._size;
      _data = new E[a._size];
      for (unsigned int i = 0; i < _size; i++) _data[i] = a._data[i];
    }
    return *this;
  }
  ~Array() { delete[] _data; }

  // Constructors
  explicit Array(unsigned int n) throw(std::bad_alloc)
      : _size(n), _data(new E[n]) {}

  // Operators
  E& operator[](unsigned int i) throw(std::exception) {
    if (i >= _size) throw std::out_of_range("Array::operator[]");
    return _data[i];
  }
  const E& operator[](unsigned int i) const throw(std::exception) {
    if (i >= _size) throw std::out_of_range("Array::operator[]");
    return _data[i];
  }

  // Accessors
  unsigned int size() const { return _size; }

 private:
  // Data
  unsigned int _size;
  E* _data;
};

template <typename E>
std::ostream& operator<<(std::ostream& os, const Array<E>& a) {
  os << "Array<E>[" << a.size() << "] = {";
  for (unsigned int i = 0; i < a.size(); i++) {
    os << a[i];
    if (i < a.size() - 1) os << ", ";
  }
  os << "}";
  return os;
}

#endif
