# In-Memory Virtual File System 

This project implements a hierarchical file structure using the **Composite Design Pattern** and enforces memory safety through modern C++ **Smart Pointers** (`std::shared_ptr` and `std::weak_ptr`).

It features a custom Command Line Interface (CLI) that supports standard shell operations like nested directory creation, file generation, and recursive deletion.

## 🚀 Key Features

* **Linux-Style CLI:** Supports standard commands: `mkdir`, `touch`, `ls`, `cd`, `pwd`, `rm`.
* **Memory Safety:** Utilizes `std::weak_ptr` for parent references to eliminate circular dependency memory leaks, ensuring full RAII compliance.
* **Composite Architecture:** Treats Files and Directories uniformly via a polymorphic `Node` base class.
* **Recursive Algorithms:** Implements Depth-First Search (DFS) for calculating directory sizes and traversing nested structures.
* **Polymorphic Behavior:** Directories can hold any object type derived from `Node` (extensible design).

## 🛠️ Installation & Build

You can compile this project on any system with a C++ compiler (GCC/Clang/MSVC).

### Prerequisites
* g++ (supporting C++17 or later)
* Make (optional, for easier building)

### Option 1: Using Make (Recommended)
If you have `make` (or `mingw32-make` on Windows) installed:
```bash
make
./vfs
# On Windows, use: ./vfs.exe
```
Option 2: Manual Compilation
If you don't have Make, run this single command:
```bash
g++ -std=c++17 main.cpp FileSystem.cpp Directory.cpp File.cpp -o vfs
./vfs
# On Windows, use: ./vfs.exe
```
## 💻 Usage Example
Once the program is running, you can interact with the virtual file system just like a real terminal.

```bash
=== C++ Virtual File System ===
Commands: mkdir, touch, ls, cd, pwd, rm, exit

> mkdir home
> cd home
> touch welcome.txt "Hello World"
> mkdir projects
> cd projects
> touch main.cpp "int main() { return 0; }"
> pwd
/home/projects/

> cd ..
> ls
Contents of home/:
  + [DIR]  projects/
    - [FILE] main.cpp (28 bytes)
  - [FILE] welcome.txt (11 bytes)

> cd ..
> rm home
Deleted home
# (Automatically cleans up all nested files and folders from memory)
```
## 🧠 Technical Design Decisions
1. The Composite Pattern
I used an abstract base class Node to define common interfaces (getSize, print). Both File and Directory inherit from Node. This allows the Directory class to store a std::vector<Node*> containing both files and other directories, treating them uniformly during traversal.

2. Solving Circular Dependencies
In a tree structure, a parent owns a child, but a child often needs to access its parent (e.g., for cd ..).

3. Recursive Traversal
Operations like ls (tree visualization) and getSize (disk usage) are implemented recursively. The Directory class delegates the task to its children, allowing the system to handle folders of arbitrary depth without complex iterative logic.
