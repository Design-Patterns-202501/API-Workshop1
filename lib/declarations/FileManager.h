#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <functional>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

class FileManager {
    public:
        FileManager() = default;
        void IterateFiles(std::string folder, std::function<void(std::string)> process);
        std::string DumpText(std::string path);
};

#endif // !FILE_MANAGER_H
