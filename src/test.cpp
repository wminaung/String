#include "Console.cpp"
#include "String.hpp"
#include <functional>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>

static int test_count = 0;
static int test_fail = 0;

class WinTest {
public:
  WinTest() {
    test_count = 0;
    test_fail = 0;
  }
  ~WinTest() {
    std::cout << std::endl
              << "------------------------------------------" << std::endl;
    std::cout << "\t\033[32m[PASS]\033[0m Test count: " << test_count
              << std::endl;
    std::cout << "\t\033[31m[FAIL]\033[0m Test fail: " << test_fail
              << std::endl;
  }

  WinTest &it(const std::string &test_case, bool passed) {
    test_count++;
    if (passed) {
      std::cout << "\033[32m[PASS]\033[0m " << test_case << std::endl;
    } else {
      std::cout << "\033[31m[FAIL]\033[0m " << test_case << std::endl;
      test_fail++;
    }

    return *this;
  }
};

int sum(int a, int b, int (*add3)(int, int)) {
  int c = add3(a, b);
  return c;
}
int main() {

  // Call function using pointer

  int result = sum(1, 2, [](int a, int b) { return a + b + 3; });

  std::cout << result << std::endl;
  return 0;
}

/*********/
/*
int main322() {

  String s1 = "hellllo world ";
  int count = 0;

  String *arr = s1.split("l", count);
  std::cout << count << " c-" << std::endl;
  for (size_t i = 0; i < count; i++) {
    std::cout << " -> " << i << " :" << arr[i] << ":" << std::endl;
  }
  delete[] arr;
  WinTest win_test;

  if (0) {
    std::cout << "------------<String::countOccurrences>------------"
              << std::endl;
    String s1 = "hello world world";
    String g = "  f f f f f f f  f f f f f f f  f f f f f f f";

    win_test.it("should return 2", s1.countOccurrences("world") == 2);
    // win_test.it("should return 3", g.countOccurrences(" ") == 3);
    std::cout << (g.countOccurrences("  f f f f f f f")) << std::endl;
  }
  return 0;

  if (10) {
    std::cout << "------------<String::countOccurrences>------------"
              << std::endl;
    String s1 = "hello world world";
    String g = "hello ggg world worlsd ggg  ggg ";

    win_test.it("should return 2", s1.countOccurrences("world") == 2);
    win_test.it("should return 3", g.countOccurrences("ggg") == 3);
  }

  if (10) {
    std::cout << "------------<String::includes>------------" << std::endl;
    String s1 = "hello world world";
    String g = "hello ggg world worlsd ggg  ggg ";

    win_test.it("should return true", s1.includes("world"));
    win_test.it("should return false", !s1.includes("worlds"));
    win_test.it("should return true", g.includes("ggg"));
  }
  if (10) {
    std::cout << "------------<String::Iterator>------------" << std::endl;
    String s1 = "12345";
    String s2 = "<b>dkdkdkd";
    for (auto ptr = s1.begin(); ptr != s1.end(); ++ptr) {
      *ptr = '0';
    }
    win_test.it("should return \"00000\"", s1 == "00000");

    int s2_len = 0;
    auto it = s2.begin();
    while (it != s2.end()) {
      s2_len++;
      ++it;
    }
    std::stringstream ss;
    ss << "should return " << s2.getLength() << std::endl;
    win_test.it(ss.str(), s2_len == s2.getLength());
  }

  if (10) {
    std::cout << "------------<String::operator+>------------" << std::endl;
    String s1 = "<a>";
    String s2 = "<b>";

    win_test.it("should return \"<a><b>\"", (s1 + s2) == "<a><b>");
    s1 = s1 + s1 + s2;
    win_test.it("should return \"<a><a><b>\"", s1 == "<a><a><b>");
  }

  if (10) {
    std::cout << "------------<String::append,+=>------------" << std::endl;
    String s1 = "<abcdef>";
    String s2 = "muda muda muda muda";
    String username = "JohnDoe";
    String mail = "@gmail.com";
    String email = username += mail;
    win_test.it("should return \"JohnDoe@gmail.com\"",
                email == "JohnDoe@gmail.com");

    s1.append(s1);
    win_test.it("should return \"<abcdef><abcdef>\"", s1 == "<abcdef><abcdef>");
    s1.append(s2);
    win_test.it("should return \"<abcdef><abcdef>muda muda muda muda\"",
                s1 == "<abcdef><abcdef>muda muda muda muda");
  }

  if (10) {
    std::cout << "------------<String::cpy>------------" << std::endl;
    String s1 = "abcdef";
    s1.cpy(s1);
    win_test.it("should return \"abcdef\"", s1 == "abcdef");
    s1.cpy("muda muda muda muda");
    win_test.it("should return \"muda muda muda muda\"",
                s1 == "muda muda muda muda");
    s1.setValue(s1.getValue());
    win_test.it("should return \"muda muda muda muda\"",
                s1 == "muda muda muda muda");
  }

  if (10) {
    std::cout << "------------<String::substr>------------" << std::endl;

    // need to fix substring
    String s1 = "aaabbb";

    win_test.it("should return aaa", s1.substr(0, 3) == "aaa");
    win_test.it("should return bbb", s1.substr(3, 3) == "bbb");
    win_test.it("should return empty string", s1.substr(3, 0) == "");
    win_test.it("should return aaabbb", s1.substr(0) == "aaabbb");
    win_test.it("should return abbb", s1.substr(2) == "abbb");
    win_test.it("should return empty string", s1.substr(s1.getLength()) == "");
  }

  if (10) {
    std::cout << "------------<String::cmp>------------" << std::endl;
    String s1 = "abc";
    String s2 = "defg";
    String s3 = "abc";
    win_test.it("should return -1", s1.cmp(s2) == -1);
    win_test.it("should return 1", s2.cmp(s1) == 1);
    win_test.it("should return 0", s1.cmp(s3) == 0);
  }

  if (10) {
    std::cout << "------------<String::trim>------------" << std::endl;
    String name = " abc ";
    String name2 = "abc";
    win_test.it("should length is 5", name.getLength() == 5);
    name.trim();
    win_test.it("should length is 3", name.getLength() == 3);
    win_test.it("should return true", name == name2);
  }

  if (10) {
    std::cout << "------------<String::operator[],<<,==,=>------------"
              << std::endl;
    String s = "Hello";
    String s2 = "Hello";
    win_test.it("should return 'H'", s[0] == 'H');
    win_test.it("should return 'o'", s[3] == 'l');
    win_test.it("should return true", s == s);
    win_test.it("should return true", s == s2);

    s[3] = 'D';
    win_test.it("should return 'D'", s[3] == 'D');
    win_test.it("should return 'HelDo'", String(s.getValue()) == "HelDo");
    win_test.it("should return false", !(s == s2));
  }

  if (10) {
    std::cout << "------------<String::at>------------" << std::endl;
    String str = "abcde";
    win_test.it("should return 'a'", str.at(0) == 'a');
    win_test.it("should return 'e'", str.at(str.getLength() - 1) == 'e');

    bool error = false;
    try {
      str.at(str.getLength());
    } catch (const std::exception &e) {
      error = true;
    }
    win_test.it("should throw error", error);
  }

  if (10) {
    std::cout << "------------<String::isEqual>------------" << std::endl;
    String s1 = "hello";
    String s2("hello");
    String s3("Hello");
    win_test.it("should return true ", s1.isEqual(s2));
    win_test.it("should return false ", !s1.isEqual(s3));
  }

  if (10) {
    std::cout << "------------<String::getLength>------------" << std::endl;
    String s1 = "hello";
    win_test.it("should return 5 ", s1.getLength() == 5);
    String s2;
    win_test.it("should return 0 ", s2.getLength() == 0);
  }

  if (10) {
    std::cout << "------------<String::getValue>------------" << std::endl;
    String s1;
    win_test.it("should return null pointer ", s1.getValue() == nullptr);
    s1 = "hello";
    win_test.it("should return hello ", std::string(s1.getValue()) == "hello");
  }

  return 0;
}
*/