# File: Makefile
# Author: Joshua T. Guerin, PhD
# Makefile for the Linked List example from class.

# Compiler Version
CC=g++

# Debugging flag -g
DEBUG=-g

# Target
TARGET=assoc

# Compile with all errors and warnings
CFLAGS=-c -Wall $(DEBUG)

# Makefile syntax:
# target: dependencies
#(tab) system command(s)

all: $(TARGET)

$(TARGET): main.o assoc.o
	$(CC) main.o assoc.o -o $(TARGET)

main.o: main.cpp assoc.h
	$(CC) $(CFLAGS) main.cpp

assoc.o: assoc.cpp assoc.h
	$(CC) $(CFLAGS) assoc.cpp

clean:
	rm *.o *~ $(TARGET)

