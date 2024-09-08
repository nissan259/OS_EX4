# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -pthread  # Include pthread support

# Target executable
TARGET = race_condition

# Source file
SRCS = race_condition.c

# Default target to build the program
all: $(TARGET)

# Rule to build the program
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Run the program normally
run: $(TARGET)
	./$(TARGET)

# Run Helgrind to detect race conditions
helgrind: $(TARGET)
	valgrind --tool=helgrind ./$(TARGET)

# Clean the compiled files
clean:
	rm -f $(TARGET) *.o
