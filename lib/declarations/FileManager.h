#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../../schemas/declarations/Booking.h"

#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

class FileManager {
public:
  const static std::string CWD;

  FileManager() = default;

  void IterateFiles(std::string folder,
                    std::function<void(std::string)> process);

  std::string DumpText(std::string path);

  bool WriteFile(std::string path, std::string content, std::string folder);

  static void EnsureDatabaseFolder() {
      std::filesystem::create_directory(CWD);
  }

};

#endif // !FILE_MANAGER_H
