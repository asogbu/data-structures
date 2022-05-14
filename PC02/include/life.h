/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: life.h
 * Contents: Funciton declarations and global variables for PC02
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_WIDTH 70
#define BOARD_HEIGHT 30

int width_add(int width_index, int width_offset);
int height_add(int height_index, int x_offset);
int adjacent_to(char board[][BOARD_WIDTH], int x_index, int y_index);
int get_num_plays(const char *num_plays);
void play_generation(char board[][BOARD_WIDTH]);
void print_board(char board[][BOARD_WIDTH]);
void read_file(char board[][BOARD_WIDTH], const char *name);
void print_to_file(char board[][BOARD_WIDTH], const char *name);

void copy_board(char source[][BOARD_WIDTH], char destination[][BOARD_WIDTH]);
