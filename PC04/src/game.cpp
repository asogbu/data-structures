/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: game.cpp
 * Contents: Function definitions for PC04
 */

#include "../include/game.h"

void initialize_board(VECTOR< VECTOR<int> >& game_board) {
	int random_number = rand() % 16;
	int row = random_number / 4;
	int col = random_number % 4;
	COUT << "Initial Location: (" << row << ", " << col << ')' << ENDL;

	game_board[row][col] = 2;
}

void print_board(const VECTOR< VECTOR<int> >& game_board, const int score) {
	COUT << "Score: " << score << '\n';
	COUT << "---------\n";
	
	for (int row = 0; row < HEIGHT; ++row) {
		COUT << '|';
		for (int col = 0; col < WIDTH; ++col) {
			int cell = game_board[row][col];
			if (cell == 0) COUT << ' ';
			else COUT << cell;
			COUT << '|';
		}
		COUT << "\n---------\n";
	}

	COUT << FLUSH;
}

bool check_board(const VECTOR< VECTOR<int> >& game_board) {
	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col < WIDTH; ++col) {
			if (game_board[col][row] == 0) return true;
		}
	}

	return false;
}

void generate_new_initial(VECTOR< VECTOR<int> >& game_board) {
	COUT << "Adding 2 to random spot on board..." << ENDL;

	bool location_found = false;
	int row, col;
	while(!location_found) {
		int random_number = rand() % 16;
		row = random_number / 4;
		col = random_number % 4;
		location_found = (game_board[col][row] == 0);
	}

	COUT << "New 2 placed at: (" << row << ", " << col << ')' << ENDL;
	game_board[col][row] = 2;
}

char get_move_choice() {
	COUT << "Make a choice to move:\n";
	COUT << "l for left, r for right, u for up, d for down: " << FLUSH;
	char input;
	CIN >> input;

	return input;
}

bool move_left(VECTOR< VECTOR<int> >& game_board, int& score, bool& win) {
	bool change = false;

	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = WIDTH - 1; col >= 1; --col) {
			if (game_board[row][col - 1] == 0) {
				change = true;
				game_board[row][col - 1] = game_board[row][col];
				game_board[row][col] = 0;
				for (int icol = col; icol <= WIDTH - 2; ++icol) {
					game_board[row][icol] = game_board[row][icol + 1];
				}
				game_board[row][WIDTH - 1] = 0;
			}
		}

  		for (int col = 0; col <= WIDTH - 2; ++col) {
			if (game_board[row][col + 1] == game_board[row][col]) {
				change = true;
				game_board[row][col] *= 2;
				int new_tile = game_board[row][col];
				if (new_tile == 2048) win = true;
				score += new_tile;
				for (int icol = col + 1; icol <= WIDTH - 2; ++icol) {
					game_board[row][icol] = game_board[row][icol + 1];
				}
				game_board[row][WIDTH - 1] = 0;
			}
		}
	}

	return change = true;
}

bool move_right(VECTOR< VECTOR<int> >& game_board, int& score, bool& win) {
	bool change = false;

	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col <= WIDTH - 2; ++col) {
			if (game_board[row][col + 1] == 0) {
				change = true;
				game_board[row][col + 1] = game_board[row][col];
				game_board[row][col] = 0;
				for (int icol = col; icol >= 1; --icol) {
					game_board[row][icol] = game_board[row][icol - 1];
				}
				game_board[row][0] = 0;
			}
		}

  		for (int col = WIDTH - 1; col >= 1; --col) {
			if (game_board[row][col - 1] == game_board[row][col]) {
				change = true;
				game_board[row][col] *= 2;
				int new_tile = game_board[row][col];
				if (new_tile == 2048) win = true;
				score += new_tile;
				for (int icol = col - 1; icol >= 1; --icol) {
					game_board[row][icol] = game_board[row][icol - 1];
				}
				game_board[row][0] = 0;
			}
		}
	}

	return change;
}

bool move_up(VECTOR< VECTOR<int> >& game_board, int& score, bool& win) {
	bool change = false;

	for (int col = 0; col < WIDTH; ++col) {
		for (int row = HEIGHT - 1; row >= 1; --row) {
			if (game_board[row - 1][col] == 0) {
				change = true;
				game_board[row - 1][col] = game_board[row][col];
				game_board[row][col] = 0;
				for (int irow = row; irow <= HEIGHT - 2; ++irow) {
					game_board[irow][col] = game_board[irow + 1][col];
				}
				game_board[HEIGHT - 1][col] = 0;
			}
		}

  		for (int row = 0; row <= HEIGHT - 2; ++row) {
			if (game_board[row + 1][col] == game_board[row][col]) {
				change = true;
				game_board[row][col] *= 2;
				int new_tile = game_board[row][col];
				if (new_tile == 2048) win = true;
				score += new_tile;
				for (int irow = row + 1; irow <= HEIGHT - 2; ++irow) {
					game_board[irow][col] = game_board[irow + 1][col];
				}
				game_board[HEIGHT - 1][col] = 0;
			}
		}
	}

	return change;
}

bool move_down(VECTOR< VECTOR<int> >& game_board, int& score, bool& win) {
	bool change = false;

	for (int col = 0; col < WIDTH; ++col) {
		for (int row = 0; row <= HEIGHT - 2; ++row) {
			if (game_board[row + 1][col] == 0) {
				change = true;
				game_board[row + 1][col] = game_board[row][col];
				game_board[row][col] = 0;
				for (int irow = row; irow >= 1; --irow) {
					game_board[irow][col] = game_board[irow - 1][col];
				}
				game_board[0][col] = 0;
			}
		}

  		for (int row = HEIGHT - 1; row >= 1; --row) {
			if (game_board[row - 1][col] == game_board[row][col]) {
				change = true;
				game_board[row][col] *= 2;
				int new_tile = game_board[row][col];
				if (new_tile == 2048) win = true;
				score += new_tile;
				for (int irow = row - 1; irow >= 1; --irow) {
					game_board[irow][col] = game_board[irow - 1][col];
				}
				game_board[0][col] = 0;
			}
		}
	}

	return change;
}

bool check_moves(VECTOR< VECTOR<int> >& game_board) {
	for (int row = 0; row < HEIGHT; ++row) {
		for (int col = 0; col < WIDTH; ++col) {
			int current_tile = game_board[row][col];
			if (col > 0) if (current_tile == game_board[row][col - 1]) return true;
			if (col < WIDTH - 1) if (current_tile == game_board[row][col + 1]) return true;
			if (row > 0) if (current_tile == game_board[row - 1][col]) return true;
			if (row < HEIGHT - 1) if (current_tile == game_board[row + 1][col]) return true;
		}
	}

	return false;
}
