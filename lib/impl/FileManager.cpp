#include "../declarations/FileManager.h"
#include <filesystem>

void FileManager::IterateFiles(std::string folder,
                               std::function<void(std::string)> process) {

  std::string path = this->CWD + folder;
  bool existDirectory = std::filesystem::is_directory(path);

  if (!existDirectory)
    return;

  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    process(entry.path());
  }
};

std::string FileManager::DumpText(std::string path) {
  std::ifstream file(path);
  if (!file)
    return "";
  std::stringstream buffer;

  buffer << file.rdbuf();

  file.close();

  return buffer.str();
};

bool FileManager::WriteFile(std::string path, std::string content,
                            std::string folder) {

  std::filesystem::create_directory(this->CWD + folder);

  // std::cout << "[FILE MANAGER] " << path << " " << content << std::endl;
  ofstream file(path);

  if (!file)
    return false;

  file << content;

  file.close();

  return true;
}
