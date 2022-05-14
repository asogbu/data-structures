/* Name: Andres Santiago Orozco Gorjon
 * Email: aorozcog@nd.edu
 * File name: sudoku.cpp
 * Contents: Function definitions for PC05
 */

#include "../include/sudoku.h"

void print_greeting() {
	COUT << "Welcome to our Sudoku Game!" << ENDL;
}

void populate_puzzle(IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku) {
	for (long unsigned int row = 0; row < ROWS; ++row) {
		for (long unsigned int col = 0; col < COLS; ++col) {
			sudoku_infile >> sudoku[row][col];
		}
	}
}

void update_puzzle(VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col) {
	sudoku[row][col] = value;
}

bool check_guess(const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col) {
	if (sudoku[row][col] != 0) return false; // Checks if there is already a value at that location

	long unsigned int irow, icol;
	for (icol = 0; icol < COLS; ++icol) if (sudoku[row][icol] == value) return false; // Check if there is the value is already in that row
	for (irow = 0; irow < ROWS; ++irow) if (sudoku[irow][col] == value) return false; // Check if there is the value is already in that column

	// Check if the 3x3 box where the row/col location resides contains the value
	long unsigned int initial_row = row - (row % 3);
	long unsigned int initial_col = col - (col % 3);
	for (irow = initial_row; irow < initial_row + 3; ++irow) {
		for (icol = initial_col; icol < initial_col + 3; ++icol) {
			if (sudoku[irow][icol] == value) return false;
		}
	}

	return true;
}

bool check_puzzle(const VECTOR< VECTOR<int> >& sudoku) {
	for (long unsigned int row = 0; row < ROWS; ++row) {
		for (long unsigned int col = 0; col < COLS; ++col) {
			if (sudoku[row][col] == 0) return false;
		}
	}

	return true;
}

bool recursive_solver(VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col) {
	// Find the initial location where the value is 0
	bool zero_found = false;
	while (row < ROWS) {
		while (col < COLS) {
			if (sudoku[row][col] == 0) {
				zero_found = true;
				break;
			}
			++col;
		}
		if (zero_found) break;
		col = 0;
		++row;
	}
	
	if (!zero_found) return true; // If no zero was found, the puzzle has been solved

	for (int sentinel = 1; sentinel <= 9; ++sentinel) {
		bool valid_guess = check_guess(sudoku, sentinel, row, col);
		update_puzzle(sudoku, sentinel, row, col);
		if (valid_guess && recursive_solver(sudoku, row, col)) return true;
		update_puzzle(sudoku, 0, row, col);
	}

	return false;
}

void print_puzzle(const VECTOR< VECTOR<int> >& sudoku) {
	for (long unsigned int row = 0; row < ROWS; ++row) {
		for (long unsigned int col = 0; col < COLS; ++col) {
			COUT << sudoku[row][col] << ' ';
		}
		COUT << '\n';
	}
	COUT << FLUSH;
}

void print_puzzle_to_file(OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku) {
	for (long unsigned int row = 0; row < ROWS; ++row) {
		for (long unsigned int col = 0; col < COLS; ++col) {
			sudoku_outfile << sudoku[row][col] << ' ';
		}
		sudoku_outfile << '\n';
	}
	sudoku_outfile << FLUSH;
}
