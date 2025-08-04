#include "FileIO.cpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class File {
private:
  std::string _filename;
  FileIO fileIO;

  bool createFile() { return fileIO.create(_filename); }

public:
  File(std::string filename) {
    if (filename.empty()) {
      //   std::cout << "filename is empty" << std::endl;
      throw std::runtime_error("Filename is empty");
    }

    _filename = filename;
    if (!createFile()) {
      //   std::cout << "File creation failed" << std::endl;
      throw std::runtime_error("File creation failed");
    }
  }

  ~File() {}

  std::string readAll() { return fileIO.read(_filename); }

  void write(std::string content) { fileIO.write(_filename, content); }

  void append(std::string content) { fileIO.append(_filename, content); }
};

int main() {
  File file("AAA.txt");
  file.append("Hello world!");
  file.append("Hel");
  std::cout << file.readAll();
  //   File file("");

  return 0;
}
