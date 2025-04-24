#ifndef STRING_H
#define STRING_H
#include <string>

class String {
private:
  char *value;
  void _initValue(const char *value);
  int length;

public:
  String();
  String(const char *value);
  String(const String &other);            // Copy constructor
  String &operator=(const String &other); // Copy assignment
  char &operator[](int index);
  bool operator==(const String &other) const;

  ~String();

  int getLength() const;
  const char *getValue() const;
  void setValue(const char *value);
  char *append(const char *appendValue);
  bool isEmpty() const;
  std::string toString() const;
  bool isEqual(const String &other) const;
  bool isEqual(const std::string &other) const;
  // char *at(int index);
  char &at(int index);
  String &trim();

  // static functions
  static bool strcopy(char *dest, const char *src);
  static int lengthof(const char *value);
};
std::ostream &operator<<(std::ostream &os, const String &str);
#endif
