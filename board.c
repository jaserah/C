#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "win.h"


/*this stores the piece that is placed in the program*/
void make_move(char** board, int col, char piece, int num_rows) {
	int i;
	for (i = num_rows - 1; i >= 0; i--) {
		if (board[i][col] == '*') {
			board[i][col] = piece;
			break;
		}
	}
}

/*this function declares who wins, or if it is a tie*/
void declare_winner(char** board, int num_rows, int num_cols, int turn, int num_pieces) {
	if (tied(board, num_rows, num_cols, num_pieces)) {
		printf("Tie game!\n");
	}
	else if (turn == 0) {
		printf("Player 2 Won!\n");
	}
	else {
		printf("Player 1 Won!\n");
	}
}

/*this function creates the board and makes an array for it*/
char** make_board(int num_rows, int num_cols) {
	char** board = (char**)malloc(num_rows * sizeof(char*));
	int i, j;

	for (i = 0; i < num_rows; i++) {
		board[i] = (char*)malloc(num_cols * sizeof(char));
		for (j = 0; j < num_cols; j++) {
			board[i][j] = '*';
		}
	}
	return board;
}

/*this function prints the board out*/
void print_board(char** board, int num_rows, int num_cols) {
	int i, j;

	for (i = 0; i < num_rows; i++) {
		printf("%d ", num_rows - i -1);
		for (j = 0; j < num_cols; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf(" ");
	for (j = 0; j < num_cols; j++) {
		printf("%d ", j);
	}
	printf("\n");
}
/*this function frees memory and destory the board*/
void destroy_board(char** board, int num_rows) {
	int i;
	for (i = 0; i < num_rows; i++) {
		free(board[i]);
	}
	free(board);
}