/* Name: Andres Santiago Orozco Gorjon (Santi)
 * Email: aorozcog@nd.edu
 * File name: game.h
 * Contents: Function declarations and global variables for PC04
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define VECTOR std::vector
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define FLUSH std::flush
#define HEIGHT 4
#define WIDTH 4
#define SIZE_T long unsigned int


// Function declarations
void initialize_board(VECTOR< VECTOR<int> >& game_board);
void print_board(const VECTOR< VECTOR<int> >& game_board, const int score);
bool check_board(const VECTOR< VECTOR<int> >& game_board);
void generate_new_initial(VECTOR< VECTOR<int> >& game_board);
char get_move_choice();
bool move_left(VECTOR< VECTOR<int> >& game_board, int& score, bool& win);
bool move_right(VECTOR< VECTOR<int> >& game_board, int& score, bool& win);
bool move_up(VECTOR< VECTOR<int> >& game_board, int& score, bool& win);
bool move_down(VECTOR< VECTOR<int> >& game_board, int& score, bool& win);
bool check_moves(VECTOR< VECTOR<int> >& game_board);

#endif
