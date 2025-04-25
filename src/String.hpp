#ifndef STRING_H
#define STRING_H
#include <string>
#include <vector>

class String {
private:
  int id;
  static int global_id_counter;
  char *value;
  void _initValue(const char *value);
  int length;

public:
  String();
  String(const char *value);
  String(std::string value);
  String(const char ch);
  String(const String &other); // Copy constructor
  ~String();

  // Operators
  String &operator=(const String &other); // Copy assignment
  char &operator[](int index);
  bool operator==(const String &other) const;
  String operator+(const String &other) const;
  String &operator+=(const String &other);

  // Member functions
  int getLength() const;
  const char *getValue() const;
  void setValue(const char *value);
  String &append(const String &other);
  bool isEmpty() const;
  std::string toString() const;
  bool isEqual(const String &other) const;
  bool isEqual(const std::string &other) const;
  char &at(const int index);
  String &trim();
  int cmp(const String &other) const;
  int cmp(const String &other, int limit) const;
  String substr(int start, int end);
  String &cpy(const String &other);
  String *split(String delimiter, int &outCount);

  // std::vector<String> split(char delimiter);

  // static functions
  static bool strcopy(char *dest, const char *src);
  static int lengthof(const char *value);
  static int diff(char a, char b);
};
std::ostream &operator<<(std::ostream &os, const String &str);
#endif
