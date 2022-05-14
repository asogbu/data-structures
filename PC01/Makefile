# Author: Andres Santiago Orozco Gorjon (Santi)
# Email: aorozcog@nd.edu 
# Contents: Makefile for PC01

# gcc is the compiler for C
PP := gcc

# CFLAGS are the flags for compiling code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

# Create function object
$(OBJ)/rotations.o: $(SRC)/rotations.c
	$(PP) $(CFLAGS) -c $(SRC)/rotations.c -o $@

$(OBJ)/PC01.o: $(SRC)/PC01.c
	$(PP) $(CFLAGS) -c $(SRC)/PC01.c -o $@

# Objects
objects := $(OBJ)/rotations.o $(OBJ)/PC01.o

# Create executable
PC01: $(objects)
	$(PP) $(CFLAGS) -o $(EXE)/PC01 $(objects)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
