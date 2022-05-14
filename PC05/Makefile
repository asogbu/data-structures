# Author: Andres Santiago Orozco Gorjon (Santi)
# Email: aorozcog@nd.edu 
# Contents: Makefile for PC05

# g++ is the compiler for C++
PP := g++

# CXXFLAGS are the compiler flags for C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# Program names variables
FUNC := sudoku
X := PC05

# Initialize the folders for the objects and executables
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# Create function object
$(OBJ)/$(FUNC).o: $(SRC)/$(FUNC).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(FUNC).cpp -o $@

$(OBJ)/$(X).o: $(SRC)/$(X).cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/$(X).cpp -o $@

# Objects
objects := $(OBJ)/$(FUNC).o $(OBJ)/$(X).o

# Create executable
$(X): $(objects)
	$(PP) $(CXXFLAGS) -o $(EXE)/$@ $(objects)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*
