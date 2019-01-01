#include <stdlib.h>
#include "win.h"

/*this function returns true when the game is over*/
bool game_over(char** board, int num_rows, int num_cols, int num_pieces) {
	return won(board, num_rows, num_cols, num_pieces) || tied(board, num_rows, num_cols, num_pieces);
}

/*this function returns true when the game is won*/
bool won(char** board, int num_rows, int num_cols, int num_pieces) {
	return horiz_win(board, num_rows, num_cols, num_pieces) || vert_win(board, num_rows, num_cols, num_pieces) || diag_win(board, num_rows, num_cols, num_pieces);
}

/*this function returns true when the pieces are in a horizontal row*/
bool horiz_win(char** board, int num_rows, int num_cols, int num_pieces) {
	int i, j, k;
	bool winner;
	char first_piece;

	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_cols - num_pieces + 1; j++) {
			winner = true;
			first_piece = board[i][j];
			if (first_piece == '*') {
				continue;
			}
			for (k = 0; k < num_pieces; k++) {
				if (first_piece != board[i][j + k]) {
					winner = false;
					break;
				}
			}
			if (winner) {
				return true;
			}
		}
	}
	return false;
}

/*this returns true if the number of pieces are in a verticle row*/
bool vert_win(char** board, int num_rows, int num_cols, int num_pieces) {
	int i, j, k; 
	char first_piece;
	bool winner;

	for (i = 0; i < num_cols; i++) {
		for (j = 0; j < num_rows - num_pieces + 1; j++) {
			winner = true;
			first_piece = board[j][i];
			if (first_piece == '*') {
				continue;
			}
			for (k = 0; k < num_pieces; k++) {
				if (first_piece != board[j+k][i]) {
					winner = false;
					break;
				}
			}
			if (winner) {
				return true;
			}
		}
	}
	return false;
}

/*this returns true if there is a diagonal that works*/
bool diag_win(char** board, int num_rows, int num_cols, int num_pieces) {
	return left_diag(board, num_rows, num_cols, num_pieces) || right_diag(board, num_rows, num_cols, num_pieces);
}

/*this funtion returns true when there is a left diagonal of num_pieces*/
bool left_diag(char** board, int num_rows, int num_cols, int num_pieces) {
	int i, j, k;
	bool winner;
	char first_piece;

	for (i = 0; i < num_rows - num_pieces + 1; i++) {
		for (j = 0; j < num_cols - num_pieces + 1; j++) {
			winner = true;
			first_piece = board[i][j];
			if (first_piece == '*') {
				continue;
			}
			for (k = 0; k < num_pieces; k++) {
				if (first_piece != board[i + k][j + k]) {
					winner = false;
					break;
				}
			}
			if (winner) {
				return true;
			}
		}
	}
	return false;
}

/*this funtion returns true when there is a right diagonal of num_pieces*/
bool right_diag(char** board, int num_rows, int num_cols, int num_pieces) {
	int i, j, k;
	bool winner;
	char first_piece;

	for (i = num_rows - 1; i >= num_rows - num_pieces + 1; i--) {
		for (j = 0; j < num_cols - num_pieces + 1; j++) {
			winner = true;
			first_piece = board[i][j];
			if (first_piece == '*') {
				continue;
			}
			for (k = 0; k < num_pieces; k++) {
				if (first_piece != board[i - k][j + k]) {
					winner = false;
					break;
				}
			}
			if (winner) {
				return true;
			}
		}
	}
	return false;
}

/*this returns true if it is tied*/
bool tied(char** board, int num_rows, int num_cols, int num_pieces) {
	return is_board_full(board, num_rows, num_cols) && !won(board, num_rows, num_cols, num_pieces);
}

/*this returns true when the board is full*/
bool is_board_full(char** board, int num_rows, int num_cols) {
	int i, j;

	for (i = 0; i < num_rows; i++) {
		for (j = 0; j < num_cols; j++) {
			if (board[i][j] == '*') {
				return false;
			}
		}
	}
	return true;
}