/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: PC02.c
 * Contents: main() for PC02
 */

#include "../include/life.h"

int main(const int argc, const char* argv[]) {
	if (argc != 4) return 1;

	char board[BOARD_HEIGHT][BOARD_WIDTH];
	read_file(board, argv[1]);
	
	int i;
	for (i = 0; i < get_num_plays(argv[2]); ++i) {
		print_board(board);
		// sleep((unsigned int) 1);
		play_generation(board);
	}

	print_board(board);
	print_to_file(board, argv[3]);

	return 0;
}
