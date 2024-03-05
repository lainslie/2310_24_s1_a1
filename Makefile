CFLAGS = -Wall -Wextra -std=c11 -g

# Project files
SOURCES = main.c a1library.c command_line.c utils.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = a1library.h command_line.h utils.h
EXECUTABLE = uqunscramble

# Default target
all: $(EXECUTABLE)

# Rule for linking the final executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Rule for compiling source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean