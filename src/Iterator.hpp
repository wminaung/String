#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T> class Iterator {
private:
  T *ptr;

public:
  Iterator(T *p) : ptr(p) {}

  ~Iterator() {}

  T &operator*() { return *ptr; }

  T *base() const { return ptr; }

  Iterator &operator++() {
    ++ptr;
    return *this;
  }
  Iterator operator++(int) {
    Iterator temp = *this; // save current state
    ++(*this);             // use prefix increment
    return temp;           // return old state
  }
  bool operator!=(const Iterator &other) const { return ptr != other.ptr; }
};

#endif
