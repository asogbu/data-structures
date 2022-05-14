/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: PC04.cpp
 * Contents: main() for PC04
 */

#include "../include/game.h"

int main() {
	VECTOR< VECTOR<int> > game_board(HEIGHT, VECTOR<int>(WIDTH, 0)); // Initialize game_board to 0
	srand((unsigned int) time(NULL)); // Seed random number generator
	int score = 0; // Initialize score

	// Set first value
	initialize_board(game_board);
	print_board(game_board, score);

	char keep_going = 'y';
	bool win = false;
	bool moves_available = true;
	bool change = true;
	while ((keep_going == 'y') && !win && moves_available) {
		if (check_board(game_board)) { // If board isn't full
			if (change) { // If board has changed
				generate_new_initial(game_board); // Set 2 at random location
				print_board(game_board, score);
			}
		} else moves_available = check_moves(game_board); // If board is full, check for eligible moves

		if (moves_available) {
			switch (get_move_choice()) {
				case 'l':
					change = move_left(game_board, score, win);
					break;
				case 'r':
					change = move_right(game_board, score, win);
					break;
				case 'u':
					change = move_up(game_board, score, win);
					break;
				case 'd':
					change = move_down(game_board, score, win);
					break;
				default:
					COUT << "Invalid movement\n";
			}

			COUT << "Board after move...\n";
			print_board(game_board, score);
	
			COUT << "Do you wish to continue? (y/n): " << FLUSH;
			CIN >> keep_going;
		}
	}

	COUT << "Game Over" << ENDL;
	return 0;
}
