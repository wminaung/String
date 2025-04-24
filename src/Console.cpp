#include <iostream>
#include <string>
#include <vector>

class Console {
public:
  // Variadic template to handle multiple values of different types
  template <typename T, typename... Args>
  static void log(const T &first, const Args &...args) {
    std::cout << first << " ";
    log(args...); // Recursive call with the remaining arguments
  }

  // Base case for recursion when no arguments are left
  static void log() { std::cout << std::endl; }

  // Specialization for handling arrays (e.g., int[] or string[])
  template <typename T> static void log(const T *array, size_t size) {
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i) {
      std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
  }

  template <typename T> static void log(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &element : vec) {
      std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
  }

  static void log(const std::string &str) { std::cout << str << std::endl; }

  static void log(int value) { std::cout << value << std::endl; }

  static void log(double value) { std::cout << value << std::endl; }
};
