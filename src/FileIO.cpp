#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class FileIO {
private:
public:
  FileIO(){};
  ~FileIO(){};

  bool create(const std::string &_filename) {
    std::ofstream outfile(_filename); // overwrite file
    if (!outfile.is_open())
      return false;
    outfile.close();
    return true;
  };

  // Create a new file (clear if exists)
  bool write(const std::string &_filename,
             const std::string &text) { // Write (overwrite)
    std::ofstream outfile(_filename, std::ios::out);
    if (!outfile.is_open())
      return false;
    outfile << text;
    outfile.close();
    return true;
  };

  bool append(const std::string &_filename,
              const std::string &text) { // Append text
    std::ofstream outfile(_filename, std::ios::app);
    if (!outfile.is_open())
      return false;
    outfile << text;
    outfile.close();
    return true;
  };

  std::string read(const std::string &_filename) { // Read whole file
    std::ifstream infile(_filename);
    if (!infile.is_open())
      return "";

    std::stringstream buffer;
    buffer << infile.rdbuf();
    infile.close();
    return buffer.str();
  };
};

// int main() {

//   FileIO file = FileIO();
//   file.create("test.txt");
//   file.append("test.txt", "Hello World! gger");
//   file.write("test.txt", "Hello World!");
//   std::cout << file.read("test.txt");

//   return 0;
// }