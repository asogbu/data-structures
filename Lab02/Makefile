# Author: Andres Santiago Orozco Gorjon (Santi)
# E-mail: aorozcog@nd.edu
#
# This is the Makefile for Lab 02 - CSE 20312

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

# Create the Singly Linked List Object
$(OBJ)/sllist.o: $(SRC)/sllist.c
	$(PP) $(CFLAGS) -c $(SRC)/sllist.c -o $@

$(OBJ)/main.o: $(SRC)/main.c
	$(PP) $(CFLAGS) -c $(SRC)/main.c -o $@

# Singly Linked List Objects
sllist_objs := $(OBJ)/sllist.o $(OBJ)/main.o

# Singly Linked List Executable and Run
sllist: $(sllist_objs)
	$(PP) $(CFLAGS) -o $(EXE)/sllist $(sllist_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
