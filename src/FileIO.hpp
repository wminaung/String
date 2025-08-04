#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileIO {
private:
public:
  FileIO();
  ~FileIO();

  bool create(const std::string &_filename);

  // Create a new file (clear if exists)
  bool write(const std::string &_filename, const std::string &text);

  bool append(const std::string &_filename, const std::string &text);

  std::string read(const std::string &_filename);
};
