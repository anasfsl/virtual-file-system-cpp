#include "File.h"

File::File(std::string n, std::string c) : Node(n), content(c) {}

int File::getSize() const {
    return content.length();
}

void File::print(int indent) const {
    // Print with indentation to show hierarchy
    std::cout << std::string(indent, ' ') << "- [FILE] " << name 
              << " (" << getSize() << " bytes)" << std::endl;
}

bool File::isDirectory() const { return false; }