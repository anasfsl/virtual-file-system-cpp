#include "FileSystem.h"
#include <iostream>
#include <vector>

FileSystem::FileSystem() {
    root = std::make_shared<Directory>("root");
    currentDirectory = root;
}

void FileSystem::mkdir(const std::string& name) {
    if (currentDirectory->getChild(name)) {
        std::cout << "Error: Directory already exists.\n";
        return;
    }
    auto newDir = std::make_shared<Directory>(name);
    currentDirectory->addNode(newDir);
}

void FileSystem::touch(const std::string& name, const std::string& content) {
    if (currentDirectory->getChild(name)) {
        std::cout << "Error: File already exists.\n";
        return;
    }
    auto newFile = std::make_shared<File>(name, content);
    currentDirectory->addNode(newFile);
}

void FileSystem::ls() {
    std::cout << "Contents of " << currentDirectory->getName() << "/:\n";
    for (const auto& pair : currentDirectory->getChildren()) {
        pair.second->print(2);
    }
}

void FileSystem::cd(const std::string& name) {
    if (name == "..") {
        auto parent = currentDirectory->getParent();
        if (parent) {
            // Safe cast from Node to Directory
            currentDirectory = std::dynamic_pointer_cast<Directory>(parent);
        } else {
            std::cout << "Error: Already at root.\n";
        }
    } else {
        auto child = currentDirectory->getChild(name);
        if (child && child->isDirectory()) {
            currentDirectory = std::dynamic_pointer_cast<Directory>(child);
        } else {
            std::cout << "Error: Directory not found.\n";
        }
    }
}

void FileSystem::pwd() {
    std::vector<std::string> path;
    std::shared_ptr<Node> curr = currentDirectory;
    
    while (curr) {
        path.push_back(curr->getName());
        curr = curr->getParent();
    }

    std::cout << "/";
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        if (*it != "root") std::cout << *it << "/";
    }
    std::cout << std::endl;
}

void FileSystem::rm(const std::string& name) {
    if (currentDirectory->getChild(name)) {
        currentDirectory->removeChild(name);
        std::cout << "Deleted " << name << "\n";
    } else {
        std::cout << "Error: Not found.\n";
    }
}