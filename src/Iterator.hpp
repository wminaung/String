#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T> class Iterator {
private:
  T *ptr;

public:
  Iterator(T *p) : ptr(p) {}

  ~Iterator() {}

  T &operator*() { return *ptr; }

  Iterator &operator++() {
    ptr++;
    return *this;
  }
  Iterator &operator++(int) {
    ptr++;
    return *this;
  }
  bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
};

#endif
