# Compiler and flags
CC = gcc
CFLAGS = -Wall -ansi -pedantic -std=c90

TARGET = xy_bits

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

xy_bits : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)