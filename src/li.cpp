#include "Iterator.hpp"
#include <functional>
#include <iostream>
#include <vector>

template <typename T> class Optional {
private:
  bool _hasValue;
  T _value;

public:
  Optional() : _hasValue(false) {}
  Optional(T val) : _hasValue(true), _value(val) {}

  bool has_value() const { return _hasValue; }

  T &operator*() { return _value; }
  const T &operator*() const { return _value; }

  T value_or(T defaultVal) const { return _hasValue ? _value : defaultVal; }

  void reset() { _hasValue = false; }
};

template <typename T> class List {
private:
  int _size;
  int _capacity;
  T *_elements;

public:
  int capacity() const { return _capacity; }
  int size() const { return _size; }
  T *data() const { return _elements; }

  void reserve(int _new_capacity) {
    _capacity = _new_capacity;
    if (_elements != nullptr)
      delete[] _elements;
    _elements = new T[_capacity];
  }
  void resize(int _new_size) {
    if (_new_size > _capacity)
      reserve(_new_size);
    for (int i = _size; i < _new_size; i++) {
      _elements[i] = T();
    }
    _size = _new_size;
  }

  const T &operator[](int index) const {
    //
    return at(index);
  }

  const T &at(int index) const {
    if (index < 0 || index >= _size)
      throw std::out_of_range("Index out of valid range");
    return _elements[index];
  }

  void push(T val) {
    if (_size < _capacity) {
      _elements[_size++] = val;
    }
  }

  Optional<T> pop() {
    if (_size == 0)
      return Optional<T>();

    if (_size > 0)
      --_size;
    T pop_value = _elements[_size];
    _elements[_size] = T();
    return pop_value;
  }

  List(int initial_capacity = 5)
      : _capacity(initial_capacity), _size(0), _elements(nullptr) {

    _elements = new T[_capacity];
  }

  ~List() {
    delete[] _elements;
    _elements = nullptr;
  }
  // map applies func to each element
  List &map(std::function<T(T)> func) {
    for (int i = 0; i < 3; i++) {
      _elements[i] = func(_elements[i]);
    }
    return *this;
  }

  List filter(std::function<bool(T)> func) {
    List filtered = List(_size);
    for (int i = 0; i < _size; i++) {
      if (func(_elements[i])) {
        filtered.push(_elements[i]);
      }
    }
    return filtered;
  }

  void print() {
    for (int i = 0; i < _size; i++) {
      std::cout << _elements[i] << " ";
    }
    std::cout << std::endl;
  }

  Iterator<T> begin() { return Iterator<T>(_elements); };
  Iterator<T> end() { return Iterator<T>(_elements + _size); }
};

class Car {
private:
  /* data */
  std::string name;

public:
  Car(std::string _name) { name = _name; }

  std::string getName() { return name; }
  void setName(std::string name) { this->name = name; }
};

int main() {
  // std::vector<int> l;
  // l.push_back(13);
  List<int> l;
  l.push(13);
  std::vector<int> vc;
  vc.reserve(100);
  vc.resize(3);

  std::cout << vc.capacity() << std::endl;
  return 0;
}

// int main() {

//   List<Car *> l;
//   Car *cp = new Car("BMW");
//   l.add(cp);
//   l.add(new Car("Mercedes"));
//   l.add(new Car("Audi"));
//   l.add(new Car("Bentley"));

//   // l.filter([](Car *c) { return c->getName() == "BMW"; });
//   (l.filter([](Car *c) { return c->getName() == "BMW"; })).print();
//   std::cout << "------------------"
//             << "\n";
//   for (auto it = l.begin(); it != l.end(); it++) {
//     std::cout << (*it.base())->getName() << "\n";
//   }

//   for (auto &&item : l) {
//     std::cout << item->getName() << "\n";
//   }

//   return 0;
// }
