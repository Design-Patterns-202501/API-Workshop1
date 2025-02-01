#include "../declarations/FileManager.h"

void FileManager::IterateFiles(std::string folder, std::function<void(std::string)> process) {

    for (const auto &entry : std::filesystem::directory_iterator("./" + folder)) {
        process(entry.path());
    }

};

std::string FileManager::DumpText(std::string path) {
    std::ifstream file(path);
    if (!file) return "";
    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
};
