# Compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Target executable
TARGET = hello

# Source file
SRCS = hello.c

# Default target to build the program
all: $(TARGET)

# Rule to build the program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean the compiled files
clean:
	rm -f $(TARGET) *.o

# Run Valgrind with GDB attached
valgrind_gdb: $(TARGET)
	valgrind --vgdb=yes --vgdb-error=0 ./$(TARGET)
