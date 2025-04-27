#ifndef STRING_H
#define STRING_H
#include <string>
#include <vector>
typedef int int_t;
class String {

private:
  int_t id;
  static int_t global_id_counter;
  char *value;
  void _initValue(const char *value);
  int_t length;

public:
  String();
  String(const char *value);
  String(std::string value);
  String(const char ch);
  String(const String &other); // Copy constructor
  ~String();

  // Operators
  String &operator=(const String &other); // Copy assignment
  char &operator[](int_t index);
  bool operator==(const String &other) const;
  String operator+(const String &other) const;
  String &operator+=(const String &other);

  // Member functions
  int_t getLength() const;
  const char *getValue() const;
  void setValue(const char *value);
  String &append(const String &other);
  bool isEmpty() const;
  std::string toString() const;
  bool isEqual(const String &other) const;
  char &at(const int_t index);
  String &trim();
  int_t cmp(const String &other) const;
  int_t cmp(const String &other, int_t limit) const;
  String substr(int_t start_index);
  String substr(int_t start, int_t end);
  String &cpy(const String &other);
  String *split(String delimiter, int_t &outCount);

  // std::vector<String> split(char delimiter);

  // static functions
  static bool strcopy(char *dest, const char *src);
  static int_t lengthof(const char *value);
  static int_t diff(char a, char b);
};
std::ostream &operator<<(std::ostream &os, const String &str);
#endif
