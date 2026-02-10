# Compiler Settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# Source Files
SOURCES = main.cpp FileSystem.cpp Directory.cpp File.cpp
HEADERS = FileSystem.h Directory.h File.h Node.h

# Object Files 
OBJECTS = $(SOURCES:.cpp=.o)

# Output Executable Name
TARGET = vfs

# Default Build 
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Dependency Rules 
main.o: main.cpp $(HEADERS)
FileSystem.o: FileSystem.cpp FileSystem.h Directory.h Node.h
Directory.o: Directory.cpp Directory.h Node.h
File.o: File.cpp File.h Node.h

# Clean Rule 
clean:
	del *.o vfs.exe