# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -IIncludes

# Source files in src/
SOURCES = $(wildcard src/*.c)

# Object files in build/
OBJECTS = $(SOURCES:src/%.c=build/%.o)

# Final executable
TARGET = client

all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Compile .c files into .o files
build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

# Create build folder if it doesn't exist
build:
	mkdir -p build

clean:
	rm -rf build $(TARGET)