#!/bin/bash

# Compiler used
COMP = gcc

# Flags and Libs
FLAGS = `pkg-config --cflags gtk4`
LIBS = `pkg-config --libs gtk4`

# Target file to compiling
FILE = drawing

main:
	$(COMP) $(FLAGS) -o $(FILE) $(FILE).c $(LIBS)
	echo Sucessfully compiled!

primebreaker:
	$(COMP) $(FLAGS) -o $(FILE) $(FILE).c $(LIBS) -lm
