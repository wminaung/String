#include "String.hpp"
#include "Console.cpp"
#include <iostream>

//-------------------- Private functions --------------------//

void String::_initValue(const char *value) {
  for (int i = 0; i <= this->length; i++) {
    this->value[i] = value[i];
  }
}

//-------------------- Public functions --------------------//

int String::getLength() const { return this->length; }

const char *String::getValue() const { return this->value; }

void String::setValue(const char *value) {

  if (this->value == value) {
    return;
  }

  if (this->value != nullptr) {
    delete[] this->value;
    this->value = nullptr;
  }
  this->length = lengthof(value);

  this->value = new char[this->length + 1];
  this->_initValue(value);
};

String &String::append(const String &other) {

  if (this->isEmpty()) {
    this->cpy(other);
    return *this;
  }

  int newLength = this->length + other.length;
  char *temp = new char[newLength + 1]; // +1 for '\0'

  // Copy this->value
  for (int i = 0; i < this->length; i++) {
    temp[i] = this->value[i];
  }

  // Append other.value
  for (int i = 0; i < other.length; i++) {
    temp[this->length + i] = other.value[i];
  }

  temp[newLength] = '\0'; // null terminator

  delete[] this->value;
  this->value = nullptr; // free old memory
  this->value = temp;
  temp = nullptr;
  this->length = newLength;

  return *this; // return current object reference
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

char &String::at(const int index) {

  if (index < 0 || index >= this->length) {
    throw std::out_of_range("Index is out of range");
  }
  return this->value[index];
}

String &String::trim() {
  if (isEmpty()) {
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
    if (!this->isEmpty()) {
      delete[] this->value;
      this->value = nullptr;
    }
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

  if (!this->isEmpty()) {
    delete[] this->value;
    this->value = nullptr;
  }
  this->value = temp;
  temp = nullptr;
  this->length = newLen;

  return *this;
}

int String::cmp(const String &other) const {
  if (this->length != other.length) {
    int min = this->length < other.length ? this->length : other.length;
    for (int i = 0; i < min; i++) {
      if (this->value[i] < other.value[i]) {
        return -1;
      } else if (this->value[i] > other.value[i]) {
        return 1;
      }
    }

    return this->length - other.length > 0 ? 1 : -1;
  }

  // if lengths are equal

  for (int i = 0; i < this->length; i++) {
    if (this->value[i] < other.value[i]) {
      return -1;
    } else if (this->value[i] > other.value[i]) {
      return 1;
    }
  }

  return 0;
}

int String::cmp(const String &other, int limit) const {

  if (limit > this->length || limit > other.length) {
    limit = this->length < other.length ? this->length : other.length;
  }

  if (this->length != other.length) {
    for (int i = 0; i < limit; i++) {
      if (this->value[i] < other.value[i]) {
        return -1;
      } else if (this->value[i] > other.value[i]) {
        return 1;
      }
    }
    return 0;
  }

  // if lengths are equal

  for (int i = 0; i < limit; i++) {
    if (this->value[i] < other.value[i]) {
      return -1;
    } else if (this->value[i] > other.value[i]) {
      return 1;
    }
  }

  return 0;
}

String String::substr(int start, int end) {

  if (start < 0 || start >= this->length) {
    throw std::out_of_range("Start index is out of range");
  }

  if (end < start || end > this->length) {
    throw std::out_of_range("End index is out of range");
  }

  if (start == end) {
    return String("");
  }

  int len = end - start;
  char *temp = new char[len + 1];
  for (int i = 0; i < len; i++) {
    temp[i] = this->value[start + i];
  }
  temp[len] = '\0';

  String result(temp);
  delete[] temp;
  temp = nullptr;

  return result;
}

String &String::cpy(const String &other) {
  if (this == &other)
    return *this;

  if (!this->isEmpty()) {
    delete[] this->value;
    this->value = nullptr;
  }
  this->length = other.length;
  this->value = new char[this->length + 1];

  for (int i = 0; i < this->length; i++) {
    this->value[i] = other.value[i];
  }

  this->value[this->length] = '\0';

  return *this;
}

String *String::split(String delimiter, int &outCount) {
  //
  int delen = delimiter.length;

  if (delen == 0) {
    outCount = this->length;
    String *arr = new String[outCount];

    for (int i = 0; i < outCount; i++) {
      arr[i] = String(this->value[i]);
    }

    for (int i = 0; i < outCount; i++) {
      std::cout << " arr[i] " << i << " " << arr[i] << std::endl;
    }

    return arr;
  }
  //

  // int index = 0;
  // int count = 0;

  // while (index < this->length) {

  // if (delimiter.cmp() == 0) {
  //   index += delen;
  //   count++;
  // } else {
  //   break;
  // }
  //

  return nullptr;
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

int String::diff(char a, char b) { return a - b; }
