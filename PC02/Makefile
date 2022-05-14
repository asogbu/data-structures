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

# Program names variables
FUNC := life
X := PC02

# Initialize the folders for the objects and executables
initialize:
	mkdir $(OBJ) $(EXE)

# Create function object
$(OBJ)/$(FUNC).o: $(SRC)/$(FUNC).c
	$(PP) $(CFLAGS) -c $(SRC)/$(FUNC).c -o $@

$(OBJ)/$(X).o: $(SRC)/$(X).c
	$(PP) $(CFLAGS) -c $(SRC)/$(X).c -o $@

# Objects
objects := $(OBJ)/$(FUNC).o $(OBJ)/$(X).o

# Create executable
$(X): $(objects)
	$(PP) $(CFLAGS) -o $(EXE)/$@ $(objects)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
