// Node.h
#pragma once
#include <string>
#include <memory>
#include <iostream>

class Node {
protected:
    std::string name;
    // WEAK POINTER
    std::weak_ptr<Node> parent;

public:
    Node(std::string n) : name(n) {}
    virtual ~Node() = default;

    // Virtual Functions
    virtual int getSize() const = 0;
    virtual void print(int indent = 0) const = 0;
    virtual bool isDirectory() const = 0;

    // Getters and Setters
    std::string getName() const { return name; }
    
    void setParent(std::shared_ptr<Node> p) {
        parent = p;
    }

    std::shared_ptr<Node> getParent() const {
        return parent.lock(); // Convert weak_ptr to shared_ptr
    }
};