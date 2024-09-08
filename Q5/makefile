# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Target executable name
TARGET = hello

# Source files
SRCS = hello.c

# Default target to build the program
all: $(TARGET)

# Rule to build the program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Rule to run the program
run: $(TARGET)
	./$(TARGET) Hello World

# Rule to run Valgrind memcheck
valgrind: $(TARGET)
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./$(TARGET) Hello World

# Clean up the compiled files
clean:
	rm -f $(TARGET) *.o
