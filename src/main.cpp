#include "Console.cpp"
#include "String.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  if (0) {
    std::cout << "------------<String::operator+>------------" << std::endl;
    String s1 = "<a>";
    String s2 = "<b>";
    std::cout << "(s1 + s2) = " << (s1 + s2)
              << std::endl; // create new String object
    std::cout << " (s1 + s1)  = " << (s1 + s1) << std::endl;
    s1 = s1 + s1 + s2;
    std::cout << "s1 = s1 + s1 + s2 = " << s1 << std::endl;
  }
  if (0) {
    std::cout << "------------<String::append>------------" << std::endl;
    String s1 = "<abcdef>";
    s1.append(s1);
    std::cout << "s1 = " << s1 << std::endl;
    s1 += s1;
    std::cout << "s1 = " << s1 << std::endl;
  }

  if (0) {
    std::cout << "------------<String::cpy>------------" << std::endl;
    String s1 = "abcdef";
    s1.cpy(s1);
    std::cout << "s1 = " << s1 << std::endl;
    s1.cpy("muda muda muda muda");
    std::cout << "s1 = " << s1 << std::endl;
    s1.setValue(s1.getValue());
    std::cout << "s1 s= " << s1 << std::endl;
  }

  if (0) {
    std::cout << "------------<String::substr>------------" << std::endl;
    String s1 = "abcdef";
    String ss = s1.substr(1, 2);
    String gg = s1.substr(0, 3);
    std::cout << "s1.substr(1, 2) = " << ss << "<<<" << std::endl;
    std::cout << "s1.substr(0, 3) = " << gg << "<<<" << std::endl;
    if (000) {
      s1.substr(0, 33232); // it will throw error
    }
  }

  if (0) {
    std::cout << "------------<String::cmp>------------" << std::endl;
    String s1 = "abc";
    String s2 = "defg";
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "s1 == s2 = " << (s1 == s2) << std::endl; // true
    std::cout << "s1.cmp(s2) = " << s1.cmp(s2) << std::endl;
    std::cout << "s1.cmp(s2) = " << s1.cmp(s2, 00) << std::endl;
  }

  if (0) {
    std::cout << "------------<String::trim>------------" << std::endl;
    String name = "";

    std::cout << "before trim:" << name << "." << std::endl;
    std::cout << "before trim:" << name.getLength() << "." << std::endl;
    std::cout << "after trim:" << name.trim() << "." << std::endl;
    std::cout << "after trim:" << name.getLength() << "." << std::endl;
  }

  if (0) {
    std::cout << "------------<String::operator[],<<,==,=>------------"
              << std::endl;
    String s = "Hello";
    String s2 = "Hello";
    std::cout << "s = " << s << std::endl;
    std::cout << "s[0] " << s[0] << std::endl;
    std::cout << "s[3] " << s[3] << std::endl;
    std::cout << "s == s = " << (s == s) << std::endl;
    std::cout << "s == s2 = " << (s == s2) << std::endl;

    s[3] = 'D';
    std::cout << "after s[3] = 'D'\ns[3] " << s[3] << std::endl;
    std::cout << "s.getValue() = " << s.getValue() << std::endl;
    std::cout << "s = " << s << std::endl;
    std::cout << "s == s2 = " << (s == s2) << std::endl;
  }

  if (0) {
    std::cout << "------------<String::at>------------" << std::endl;
    String str = "hello";

    std::cout << "str.at(3) <----> " << str.at(3) << std::endl;
    str.at(3) = 'D';
    std::cout << "str.at(3) <----> " << str.at(3) << std::endl;
    std::cout << "str.getValue() <----> " << str.getValue() << std::endl;
    std::cout << " <----> " << std::endl;
    // std::cout << str.at(14) << " <----> " << std::endl;
  }

  if (0) {
    std::cout << "------------<String::isEqual>------------" << std::endl;
    String s1 = "hello";
    String s2("hello");
    String s3("Hello");

    std::cout << "s1.isEqual(s2)  <----> " << s1.isEqual(s2) << std::endl;
    std::cout << "s2.isEqual(s3) <----> " << s2.isEqual(s3) << std::endl;
  }

  if (0) {
    std::cout << "------------<String::getLength>------------" << std::endl;
    String str = "hello";

    std::cout << "str.getLength() <----> " << str.getLength() << std::endl;

    std::cout << " <----> " << std::endl;
    std::cout << "str.getLength()  <----> " << str.getLength() << std::endl;
  }

  if (0) {
    std::cout << "------------<String::getValue>------------" << std::endl;
    String s;
    s.setValue("hello");
    String s2(s);

    std::cout << "s2.getValue() " << s2.getValue() << std::endl;

    s2 = s;
    std::cout << "s2.getValue() " << s2.getValue() << std::endl;
    std::cout << "s2.getLength() " << s2.getLength() << std::endl;

    std::cout << "s.getValue() <----> " << std::endl;
    std::cout << "s.getLength() <----> " << s.getLength() << std::endl;
    s.append(" world!");
    std::cout << "s.getValue() <----> " << s.getValue() << std::endl;
    std::cout << "s.getLength() <----> " << s.getLength() << std::endl;
    s.append(" how are you?");
    std::cout << "s.getValue() <----> " << s.getValue() << std::endl;
    std::cout << " <----> " << s.getLength() << std::endl;
  }

  return 0;
}
