# Compiler and flags
CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c90

# Targets
TARGET = adjacency

# Source files
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Main
all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)