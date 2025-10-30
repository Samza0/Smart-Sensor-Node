# Compiler
CC = gcc

# Compiler flags (include directory added here)
CFLAGS = -Wall -g -IIncludes

# Source files
SRC = src/main.c src/Network.c src/Utils.c

# Object files
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = smart_sensor

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJ) $(TARGET)