#include "String.hpp"
#include <iostream>

int String::global_id_counter = 0;

String::String() : value(nullptr), length(0) {
  this->id = ++String::global_id_counter;
  std::cout << std::endl << "String " << this->id << " created." << std::endl;
}

/**
 * Constructs a String object from a C-style string.
 * Allocates memory for the string, initializes its length,
 * and copies the content of the input C-style string.
 *
 * @param value A pointer to a null-terminated C-style string
 *              that will be used to initialize the String object.
 */

String::String(const char *value) : String() {
  this->length = lengthof(value);
  this->value = new char[this->length + 1];
  this->_initValue(value);
}

/**
 * Constructs a String object from a C++ string object.
 * Allocates memory for the string, initializes its length,
 * and copies the content of the input C++ string.
 *
 * @param value The C++ string object that will be used to
 *              initialize the String object.
 */
String::String(std::string value) : String() {
  this->length = value.length();
  this->value = new char[this->length + 1];
  this->_initValue(value.c_str());
}

/**
 * Constructs a String object from a single character.
 * Allocates memory for the string, initializes its length
 * to 1, and copies the character to the allocated memory.
 *
 * @param ch The character that will be used to initialize the String object.
 */
String::String(const char ch) : String() {
  this->length = 1;
  this->value = new char[this->length + 1];
  this->value[0] = ch;
  this->value[1] = '\0';
}

/**
 * Copy constructor. Creates a deep copy of the input String object.
 *
 * @param other The String object that will be used to initialize the
 *              new String object.
 */
String::String(const String &other) : String() {
  this->length = other.length;              // Copy the length
  this->value = new char[this->length + 1]; // Allocate new memory
  for (int i = 0; i < this->length; i++) {
    this->value[i] = other.value[i]; // Copy each character
  }
  this->value[this->length] = '\0'; // Add null terminator
}

String::~String() {
  //
  std::cout << std::endl
            << "String id = " << this->id << " value = " << this->value
            << " deleted" << std::endl;
  delete[] this->value;
  this->value = nullptr;
}
