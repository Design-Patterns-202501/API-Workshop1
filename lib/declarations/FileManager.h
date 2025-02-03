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

  std::string CWD = std::filesystem::current_path().string() + "/database/";

  FileManager() = default;

  void IterateFiles(std::string folder,
                    std::function<void(std::string)> process);

  std::string DumpText(std::string path);

  bool WriteFile(std::string path, std::string content, std::string folder);
};

#endif // !FILE_MANAGER_H
