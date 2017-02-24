#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class FileManager {
 public:
  FileManager();
  ~FileManager();

  void load_content(const char *filename,
                    std::vector<std::vector<std::string>> &attributes,
                    std::vector<std::vector<std::string>> &contents);

 private:
  std::vector<std::string> temp_attributes;
  std::vector<std::string> temp_contents;
};

#endif  // FILEMANAGER_H
