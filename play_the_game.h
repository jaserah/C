#ifndef PLAY_THE_GAME_H
	#define PLAY_THE_GAME_H
	#include <stdbool.h>

	void play_game(char** board, int turn, int num_rows, int num_cols, int num_pieces);
	int get_valid_move(char** board, int num_rows, int num_col);
	bool is_valid_move(int num_args_read, int num_args_needed, char** board, int col, int num_rows, int num_cols);
	bool inbounds(int col, int num_cols);
#endif