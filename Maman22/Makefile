# Compiler and flags
CC = gcc
CFLAGS = -Wall -fsanitize=address -ansi -pedantic -std=c90 -g
LDFLAGS = -lm

TARGET = mycomp

SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)