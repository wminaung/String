#include "String.hpp"
#include <iostream>
#include <string>

int main() {
  String p = "John Doe";
  int i = 0;
  for (auto ptr = p.begin(); ptr != p.end(); ++ptr) {
    i++;
    if (i == 3) {
      *ptr = '3';
    }
    std::cout << *ptr << '-';
  }
  std::cout << std::endl;
  for (auto ptr = p.begin(); ptr != p.end(); ++ptr) {
    std::cout << *ptr << '-';
  }
  return 0;
  ///
}
