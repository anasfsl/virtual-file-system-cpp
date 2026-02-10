#pragma once
#include "Directory.h"
#include "File.h"
#include <memory>
#include <string>

class FileSystem {
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;

public:
    FileSystem();

    void mkdir(const std::string& name);
    void touch(const std::string& name, const std::string& content);
    void ls();
    void cd(const std::string& name);
    void pwd();
    void rm(const std::string& name);
};