#pragma once
#include "Node.h"
#include <map>
#include <vector>

// Inherits from enable_shared_from_this to allow "safe" 'this' pointers
class Directory : public Node, public std::enable_shared_from_this<Directory> {
    std::map<std::string, std::shared_ptr<Node>> children;

public:
    Directory(std::string n);

    void addNode(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getChild(const std::string& name);
    std::map<std::string, std::shared_ptr<Node>>& getChildren();
    void removeChild(const std::string& name);

    // Overrides
    int getSize() const override;
    void print(int indent = 0) const override;
    bool isDirectory() const override;
};