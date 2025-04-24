#include "String.hpp"
#include <iostream>

String::String() : value(nullptr), length(0) {}

String::String(const char *value) : String() {
  this->length = lengthof(value);
  this->value = new char[this->length + 1];
  this->_initValue(value);
}

// Deep copy constructor
String::String(const String &other) {
  this->length = other.length;              // Copy the length
  this->value = new char[this->length + 1]; // Allocate new memory
  for (int i = 0; i < this->length; i++) {
    this->value[i] = other.value[i]; // Copy each character
  }
  this->value[this->length] = '\0'; // Add null terminator
}

// Copy assignment operator
String &String::operator=(const String &other) {
  if (this != &other) {                       // Prevent self-assignment
    delete[] this->value;                     // Free existing memory
    this->length = other.length;              // Copy the length
    this->value = new char[this->length + 1]; // Allocate new memory
    for (int i = 0; i < this->length; i++) {
      this->value[i] = other.value[i]; // Copy each character
    }
    this->value[this->length] = '\0'; // Add null terminator
  }
  return *this; // Return the current object to allow chaining (e.g., a = b = c)
}

char &String::operator[](int index) {
  //
  return this->at(index);
}

bool String::operator==(const String &other) const {
  return this->isEqual(other);
}

String::~String() { delete[] value; }

//-------------------- Private functions --------------------//

void String::_initValue(const char *value) {
  this->value = new char[this->length + 1];
  for (int i = 0; i <= this->length; i++) {
    this->value[i] = value[i];
  }
}

//-------------------- Public functions --------------------//

int String::getLength() const { return this->length; }

const char *String::getValue() const {
  //
  return this->value;
}

void String::setValue(const char *value) {
  if (this->value != nullptr) {
    delete[] this->value;
  }
  this->length = lengthof(value);

  this->value = new char[this->length + 1];
  this->_initValue(value);
};

char *String::append(const char *appendValue) {

  if (this->value == nullptr) {
    this->length = lengthof(appendValue);
    this->value = new char[this->length + 1];
    strcopy(this->value, appendValue);
    return this->value;
  }

  int newLength = this->length + lengthof(appendValue);
  std::cout << this->length << "+" << lengthof(appendValue) << std::endl;
  std::cout << newLength << std::endl;

  char *temp = new char[newLength + 1];

  strcopy(temp, this->value);                // copy old value
  strcopy(temp + this->length, appendValue); // append new value
  delete[] this->value;                      // free old memory
  this->value = temp;
  this->length = newLength;

  return this->value;
}

bool String::isEmpty() const {
  return this->length == 0 || this->value == nullptr;
}

std::string String::toString() const {
  return std::string(this->value ? this->value : "");
}

bool String::isEqual(const String &other) const {

  if (this->length != other.length) {
    return false;
  }
  for (int i = 0; i < this->length; i++) {
    if (this->value[i] != other.value[i]) {
      return false;
    }
  }
  return true;
}

bool String::isEqual(const std::string &other) const {

  if (this->length != static_cast<int>(other.length())) {
    return false;
  }

  for (int i = 0; i < this->length; i++) {
    if (this->value[i] != other[i]) {
      return false;
    }
  }
  return true;
}

// char *String::at(int index) {
//   if (index < 0 || index >= this->length) {
//     throw std::out_of_range("Index is out of range");
//   }
//   return &this->value[index];
// }

char &String::at(int index) {

  if (index < 0 || index >= this->length) {
    throw std::out_of_range("Index is out of range");
  }
  return this->value[index];
}

String &String::trim() {
  if (this->length == 0) {
    return *this;
  }
  int start = 0;
  while (this->value[start] == ' ') {
    start++;
  }
  int end = this->length - 1;

  while (this->value[end] == ' ') {
    end--;
  }

  if (start == 0 && end == this->length - 1) {
    return *this;
  }

  if (end < start) {
    delete[] this->value;
    this->value = new char[1];
    this->value[0] = '\0';
    this->length = 0;
    return *this;
  }

  int newLen = end - start + 1;
  char *temp = new char[newLen + 1];
  for (int i = 0; i < newLen; ++i) {
    temp[i] = this->value[start + i];
  }
  temp[newLen] = '\0';

  delete[] this->value;
  this->value = temp;
  this->length = newLen;

  return *this;
}

//-------------------- Static functions --------------------//

bool String::strcopy(char *dest, const char *src) {
  if (dest == nullptr || src == nullptr)
    return false;

  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0'; // Don't forget the null terminator

  return true;
}

int String::lengthof(const char *value) {
  int count = 0;
  while (value[count] != '\0') {
    count++;
  }
  return count;
}

//-------------------- Non member functions --------------------//
std::ostream &operator<<(std::ostream &os, const String &str) {
  os << str.getValue();
  return os;
}