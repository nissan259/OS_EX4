# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -pthread

# Target executable
TARGET = main

# Source files
SRCS = Singleton.cpp Guard.cpp main.cpp

# Header files
HDRS = Singleton.hpp Guard.hpp

# Build target
all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean target
clean:
	rm -f $(TARGET) *.o
