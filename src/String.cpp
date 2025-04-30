#include "String.hpp"
#include "Iterator.hpp"
#include <iostream>

//-------------------- Private functions --------------------//

void String::_copyfrom(const char *value) {
  for (int_t i = 0; i <= this->length; i++) {
    this->value[i] = value[i];
  }
}

//-------------------- Public functions --------------------//

int_t String::getLength() const { return this->length; }

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
  this->_copyfrom(value);
};

String &String::append(const String &other) {

  if (this->isEmpty()) {
    this->cpy(other);
    return *this;
  }

  int_t newLength = this->length + other.length;
  char *temp = new char[newLength + 1]; // +1 for '\0'

  // Copy this->value
  for (int_t i = 0; i < this->length; i++) {
    temp[i] = this->value[i];
  }

  // Append other.value
  for (int_t i = 0; i < other.length; i++) {
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
  for (int_t i = 0; i < this->length; i++) {
    if (this->value[i] != other.value[i]) {
      return false;
    }
  }
  return true;
}

char &String::at(const int_t index) {

  if (index < 0 || index >= this->length) {
    throw std::out_of_range("Index is out of range");
  }
  return this->value[index];
}

String &String::trim() {
  if (isEmpty()) {
    return *this;
  }
  int_t start = 0;
  while (this->value[start] == ' ') {
    start++;
  }
  int_t end = this->length - 1;

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

  int_t newLen = end - start + 1;
  char *temp = new char[newLen + 1];
  for (int_t i = 0; i < newLen; ++i) {
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

int_t String::cmp(const String &other) const {
  if (this->length != other.length) {
    int_t min = this->length < other.length ? this->length : other.length;
    for (int_t i = 0; i < min; i++) {
      if (this->value[i] < other.value[i]) {
        return -1;
      } else if (this->value[i] > other.value[i]) {
        return 1;
      }
    }

    return this->length - other.length > 0 ? 1 : -1;
  }

  // if lengths are equal

  for (int_t i = 0; i < this->length; i++) {
    if (this->value[i] < other.value[i]) {
      return -1;
    } else if (this->value[i] > other.value[i]) {
      return 1;
    }
  }

  return 0;
}

int_t String::cmp(const String &other, int_t limit) const {

  if (limit > this->length || limit > other.length) {
    limit = this->length < other.length ? this->length : other.length;
  }

  if (this->length != other.length) {
    for (int_t i = 0; i < limit; i++) {
      if (this->value[i] < other.value[i]) {
        return -1;
      } else if (this->value[i] > other.value[i]) {
        return 1;
      }
    }
    return 0;
  }

  // if lengths are equal

  for (int_t i = 0; i < limit; i++) {
    if (this->value[i] < other.value[i]) {
      return -1;
    } else if (this->value[i] > other.value[i]) {
      return 1;
    }
  }

  return 0;
}

String String::substr(int_t start_index) {

  if (start_index < 0 || start_index >= this->length) {
    return String("");
  }

  int_t len = this->length - start_index;
  char *temp = new char[len + 1];
  for (int_t i = 0; i < len; i++) {
    temp[i] = this->value[start_index + i];
  }
  temp[len] = '\0';

  String result(temp);
  delete[] temp;
  temp = nullptr;

  return result;
}
String String::substr(int_t start_index, int_t length) {

  if (start_index < 0 || start_index >= this->length || length <= 0) {
    return String("");
  }

  int_t len = length;
  if (start_index + length > this->length) {
    len = this->length - start_index;
  }

  char *temp = new char[len + 1];
  for (int_t i = 0; i < len; i++) {
    temp[i] = this->value[start_index + i];
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

  for (int_t i = 0; i < this->length; i++) {
    this->value[i] = other.value[i];
  }

  this->value[this->length] = '\0';

  return *this;
}

String *String::split(const String delimiter, int_t &outCount) {
  //
  int_t delen = delimiter.length;
  if (delen == 0) {
    outCount = this->length;
    String *arr = new String[outCount];

    for (int_t i = 0; i < outCount; i++) {
      arr[i] = String(this->value[i]);
    }
    return arr;
  }

  int_t start = 0;
  int_t arrSize = this->countOccurrences(delimiter) + 1;

  outCount = arrSize;
  String *arr = new String[outCount];

  // split parts
  int_t arrIndex = 0;
  for (int_t i = 0; i <= this->length - delen;) {
    // bool match = true;
    bool match = this->substr(i, delen) == delimiter;
    if (match) {
      int_t len = i - start;
      char *sub = new char[len + 1];
      for (int_t k = 0; k < len; k++) {
        sub[k] = this->value[start + k];
      }
      sub[len] = '\0';
      arr[arrIndex++] = String(sub);
      delete[] sub;

      i += delen;
      start = i;
    } else {
      i++;
    }
  }

  // last part
  int_t len = this->length - start;
  char *sub = new char[len + 1];
  for (int_t k = 0; k < len; k++) {
    sub[k] = this->value[start + k];
  }
  sub[len] = '\0';
  arr[arrIndex++] = String(sub);
  delete[] sub;

  return arr;
}

Iterator<char> String::begin() { return Iterator<char>(this->value); }

Iterator<char> String::end() {
  return Iterator<char>(this->value + this->length);
}

bool String::includes(String searchString) {
  // search string must be less than or equal to this->length
  if (searchString.length > this->length)
    return false;

  // limit the search
  int_t limit = this->length - searchString.length + 1;
  for (int_t i = 0; i < limit; i++) {
    // substring must equal search string
    String substr = this->substr(i, searchString.length);
    if (substr == searchString) {
      return true;
    }
  }

  return false;
}

int_t String::countOccurrences(String target) {
  if (target.length > this->length)
    return 0;

  int_t count = 0;
  int_t limit = this->length - target.length + 1;
  for (int_t i = 0; i < limit; i++) {
    String substr = this->substr(i, target.length);
    if (substr == target) {
      count++;
    }
  }

  return count;
}

//-------------------- Static functions --------------------//

bool String::strcopy(char *dest, const char *src) {
  if (dest == nullptr || src == nullptr)
    return false;

  int_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0'; // Don't forget the null terminator

  return true;
}

int_t String::lengthof(const char *value) {
  int_t count = 0;
  while (value[count] != '\0') {
    count++;
  }
  return count;
}

int_t String::diff(char a, char b) { return a - b; }
