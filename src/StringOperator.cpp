#include "String.hpp"
#include <iostream>
/*
 * Copy assignment operator.
 */
String &String::operator=(const String &other) {
  if (this != &other) { // Prevent self-assignment
    if (!this->isEmpty()) {
      delete[] this->value; // Free existing memory
      this->value = nullptr;
    }
    this->length = other.length;              // Copy the length
    this->value = new char[this->length + 1]; // Allocate new memory
    for (int_t i = 0; i < this->length; i++) {
      this->value[i] = other.value[i]; // Copy each character
    }
    this->value[this->length] = '\0'; // Add null terminator
  }
  return *this; // Return the current object to allow chaining (e.g., a = b = c)
}

/**
 * Overload the [] operator to access characters in a String object.
 */
char &String::operator[](int_t index) {
  //
  return this->at(index);
}

/**
 * Overload the == operator to compare two String objects.
 */
bool String::operator==(const String &other) const {
  return this->isEqual(other);
}

String String::operator+(const String &other) const {
  int_t newLength = this->length + other.length;
  char *newValue = new char[newLength + 1];

  // Copy first string
  for (int_t i = 0; i < this->length; i++) {
    newValue[i] = this->value[i];
  }
  // Append second string
  for (int_t i = 0; i < other.length; i++) {
    newValue[this->length + i] = other.value[i];
  }
  newValue[newLength] = '\0';
  String result;
  result.length = newLength;
  result.value = newValue;

  return result;
}

/*
 * Overload the += operator to append a String object to another String object.
 */
String &String::operator+=(const String &other) { return this->append(other); }

//-------------------- Non member functions --------------------//
/**
 * Overload the << operator to print a String object.
 */
std::ostream &operator<<(std::ostream &os, const String &str) {
  os << str.getValue();
  return os;
}