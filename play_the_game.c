#include <stdlib.h>
#include <stdio.h>
#include "play_the_game.h"
#include "board.h"
#include "win.h"

/*this function checks if the game is over and while it isn't, it loops printing the board, 
asking for input and then placing the move on the board, and switching turns. when the game is over, 
it will print the board and declare the winner*/
void play_game(char** board, int turn, int num_rows, int num_cols, int num_pieces) {
	char pieces[] = "XO";
	while (!game_over(board, num_rows, num_cols, num_pieces)) {
		print_board(board, num_rows, num_cols);
		int col = get_valid_move(board, num_rows, num_cols);
		make_move(board, col, pieces[turn], num_rows);

		turn = (turn + 1) % 2;
	}
	print_board(board, num_rows, num_cols);
	declare_winner(board, num_rows, num_cols, turn, num_pieces);
}

/*this function asks the user for a play and then sends it through the function to check 
if it is valid*/
int get_valid_move(char** board, int num_rows, int num_cols) {
	int col = 0;
	int num_args_read;
	do {
		printf("Enter a column between 0 and %d to play in: ", (num_cols - 1));
		num_args_read = scanf("%d", &col);
	} while (!is_valid_move(num_args_read, 1, board, col, num_rows, num_cols));

	return col;
}

/*this function makes sure that the input is valid and can be in the program*/
bool is_valid_move(int num_args_read, int num_args_needed, char** board, int col, int num_rows, int num_cols) {
	if (num_args_read != num_args_needed) {
		printf("num args wrong\n");
		return false;
	}
	else if (!inbounds(col, num_cols)) {
		return false;
	}
	else if (board[0][col] != '*') {
		return false;
	}
	else {
		return true;
	}
}

/*this function checks if the input is within the bounds of the board*/
bool inbounds(int col, int num_cols) {
	return col >= 0 && col < num_cols;
}