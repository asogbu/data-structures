/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: life.c
 * Contents: Function definitions for PC02
 */

#include "../include/life.h"

int width_add(int width_index, int width_offset) {
	int result = (width_index + width_offset) % BOARD_WIDTH;
	if (result < 0) result += BOARD_WIDTH;
	return result;
}

int height_add(int height_index, int x_offset) {
	int result = (height_index + x_offset) % BOARD_HEIGHT;
	if (result < 0) result += BOARD_HEIGHT;
	return result;
}

int adjacent_to(char board[][BOARD_WIDTH], int x_index, int y_index) {
	int moves[] = {-1, 0, 1};
	int n_moves = sizeof(moves)/sizeof(moves[0]);

	int neighbors = 0;
	int i, j;
	for (i = 0; i < n_moves; ++i) {
		int x_check = width_add(x_index, moves[i]);
		for (j = 0; j < n_moves; ++j) {
			int y_check = height_add(y_index, moves[j]);
			if ((x_check == x_index) && (y_check == y_index)) continue;
			if (board[y_check][x_check] == 'X') ++neighbors;
		}
	}

	return neighbors;
}

int get_num_plays(const char *num_plays) {
	return atoi(num_plays);
}

void play_generation(char board[][BOARD_WIDTH]) {
	char past_board[BOARD_HEIGHT][BOARD_WIDTH];
	copy_board(board, past_board);

	int i, j;
	for (i = 0; i < BOARD_HEIGHT; ++i) {
		for (j = 0; j < BOARD_WIDTH; ++j) {
			int neighbors = adjacent_to(past_board, j, i);
			if (neighbors > 4) neighbors = 4;
			switch (neighbors) {
				case 0: 
				case 1: board[i][j] = '.';
					break;
				case 2:
					break;
				case 3: board[i][j] = 'X';
					break;
				case 4: board[i][j] = '.';
					break;
				default:
					fprintf(stderr, "Error in play_generation()\n");
			}
		}
	}
}

void print_board(char board[][BOARD_WIDTH]) {
	system("clear");

	int i, j;
	for (i = 0; i < BOARD_HEIGHT; ++i) {
		for (j = 0; j < BOARD_WIDTH; ++j) {
			fprintf(stdout, "%c", board[i][j]);
		}
		fprintf(stdout, "\n");
	}
}

void read_file(char board[][BOARD_WIDTH], const char *name) {
	FILE * input = fopen(name, "r");

	int i, j;
	for (i = 0; i < BOARD_HEIGHT; ++i) {
		for (j = 0; j < BOARD_WIDTH; ++j) {
			fscanf(input, " %c", &board[i][j]);
		}
	}

	fclose(input);
}

void print_to_file(char board[][BOARD_WIDTH], const char *name) {
	FILE * output = fopen(name, "w");

	int i, j;
	for (i = 0; i < BOARD_HEIGHT; ++i) {
		for (j = 0; j < BOARD_WIDTH; ++j) {
			fprintf(output, "%c", board[i][j]);
		}
		fprintf(output, "\n");
	}

	fclose(output);
}

void copy_board(char source[][BOARD_WIDTH], char destination[][BOARD_WIDTH]) {
	int i, j;
	for (i = 0; i < BOARD_HEIGHT; ++i) {
		for (j = 0; j < BOARD_WIDTH; ++j) {
			destination[i][j] = source[i][j];
		}
	}
}
