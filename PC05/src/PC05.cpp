/* Name: Andres Santiago Orozco Gorjon
 * Email: aorozcog@nd.edu
 * File name: PC05.cpp
 * Contents: main() for PC05
 */

#include "../include/sudoku.h"

int main(const int argc, const char* argv[]) {
	if (argc != 3) {
		COUT << "Usage: " << argv[0] << " input_file output_file" << ENDL;
		return 1;
	}

	print_greeting();

	VECTOR< VECTOR<int> > sudoku(ROWS, VECTOR<int>(COLS, 0)); // Initialize sudoku to 0's
	IFSTREAM sudoku_infile(argv[1]); // Open stream to input file
	populate_puzzle(sudoku_infile, sudoku); // Populate sudoku from input file
	sudoku_infile.close();

	COUT << "Initial Puzzle:" << ENDL;
	print_puzzle(sudoku);

	COUT << "Attempting to solve the Puzzle..." << ENDL;
	if (recursive_solver(sudoku, 0, 0)) COUT << "You solved the puzzle!" << ENDL;
	else COUT << "Puzzle is not solvable" << ENDL;
	print_puzzle(sudoku);

	// Printing to output file
	OFSTREAM sudoku_outfile(argv[2]);
	print_puzzle_to_file(sudoku_outfile, sudoku);
	sudoku_outfile.close();

	return 0;
}
