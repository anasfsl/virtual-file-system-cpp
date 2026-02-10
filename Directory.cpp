#include "Directory.h"

Directory::Directory(std::string n) : Node(n) {}

void Directory::addNode(std::shared_ptr<Node> node) {
    children[node->getName()] = node;
    node->setParent(shared_from_this());
}

std::shared_ptr<Node> Directory::getChild(const std::string& name) {
    if (children.find(name) != children.end()) {
        return children[name];
    }
    return nullptr;
}

std::map<std::string, std::shared_ptr<Node>>& Directory::getChildren() {
    return children;
}

void Directory::removeChild(const std::string& name) {
    children.erase(name);
}

int Directory::getSize() const {
    int total = 0;
    for (const auto& pair : children) {
        total += pair.second->getSize(); // Recursive call
    }
    return total;
}

void Directory::print(int indent) const {
    std::cout << std::string(indent, ' ') << "+ [DIR]  " << name << "/" << std::endl;
    for (const auto& pair : children) {
        pair.second->print(indent + 2); // Recursive print
    }
}

bool Directory::isDirectory() const { return true; }