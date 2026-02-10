#pragma once
#include "Node.h"

class File : public Node {
    std::string content;

public:
    File(std::string n, std::string c = "");
    
    // Overriding base class methods
    int getSize() const override;
    void print(int indent = 0) const override;
    bool isDirectory() const override;
};