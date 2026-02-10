#include <iostream>
#include <string>
#include <sstream>
#include "FileSystem.h"

int main() {
    FileSystem fs;
    std::string input;

    std::cout << "=== C++ Virtual File System ===\n";
    std::cout << "Commands: mkdir <name>, touch <name> <content>, ls, cd <name>, pwd, rm <name>, exit\n\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        if (input.empty()) continue;

        std::string command, arg1, arg2; 
        std::stringstream ss(input);
        ss >> command >> arg1;
        std::getline(ss, arg2);
        
        if (!arg2.empty() && arg2[0] == ' ') arg2.erase(0, 1); // Trim leading space

        if (command == "exit") break;
        else if (command == "mkdir") fs.mkdir(arg1);
        else if (command == "touch") fs.touch(arg1, arg2);
        else if (command == "ls")    fs.ls();
        else if (command == "cd")    fs.cd(arg1);
        else if (command == "pwd")   fs.pwd();
        else if (command == "rm")    fs.rm(arg1);
        else std::cout << "Unknown command.\n";
    }

    return 0;
}