#include "inc/filemanager.hpp"

FileManager::FileManager() {}

FileManager::~FileManager() {}

enum LoadState { ATTRIBUTES, CONTENTS };

int state;

void FileManager::load_content(
    const char *filename, std::vector<std::vector<std::string>> &attributes,
    std::vector<std::vector<std::string>> &contents) {
  temp_attributes.clear();
  temp_contents.clear();
  std::ifstream openfile(filename);

  if (openfile.is_open()) {
    while (!openfile.eof()) {
      std::string line;
      std::getline(openfile, line);
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

      if (line.find("Load=") != std::string::npos) {
        state = ATTRIBUTES;
        line.erase(0, line.find('=') + 1);
        temp_attributes.clear();
      } else {
        state = CONTENTS;
        temp_contents.clear();
      }
      line.erase(std::remove(line.begin(), line.end(), '['), line.end());
      std::stringstream str(line);
      while (str) {
        std::getline(str, line, ']');
        if (line != "") {
          if (state == ATTRIBUTES) {
            temp_attributes.push_back(line);
          } else {
            temp_contents.push_back(line);
          }
          std::cout << line << std::endl;
        }
      }

      if (state == CONTENTS && temp_contents.size() > 0) {
        attributes.push_back(temp_attributes);
        contents.push_back(temp_contents);
      }
    }
  }
}
