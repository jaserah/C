#ifndef WIN_H
	#define WIN_H
	#include <stdbool.h>
	
	bool game_over(char** board, int num_rows, int num_cols, int num_pieces);
	bool won(char** board, int num_rows, int num_cols, int num_pieces);
	bool horiz_win(char** board, int num_rows, int num_cols, int num_pieces);
	bool vert_win(char** board, int num_rows, int num_cols, int num_pieces);
	bool diag_win(char** board, int num_rows, int num_cols, int num_pieces);
	bool left_diag(char** board, int num_rows, int num_cols, int num_pieces);
	bool right_diag(char** board, int num_rows, int num_cols, int num_pieces);
	bool tied(char** board, int num_rows, int num_cols, int num_pieces);
	bool is_board_full(char** board, int num_rows, int num_cols);

#endif