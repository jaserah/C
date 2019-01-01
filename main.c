#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "win.h"
#include "play_the_game.h"

/*this program takes input from the user and then creates a board depending on the columns and 
rows and then asks the user to input the col they want to play in and then plays a game of connect-n 
depending on the number of pieces they want in a row*/


/*this sets up the board by making it work and then creating the turns*/
void set_up(char*** board, int *turn, int num_rows, int num_cols) {
	*board = make_board(num_rows, num_cols);
	*turn = 0;
}

/*this is the main function and will take the arguments from the user and then will set up the board, play
the game and then eventually destroy the board*/
int main(int argc, char* argv[]) {
	char** board;
	int turn;
	int num_rows, num_cols, num_pieces;

	if (argc == 4) {
		sscanf(argv[1], "%d", &num_rows);
		sscanf(argv[2], "%d", &num_cols);
		sscanf(argv[3], "%d", &num_pieces);
	}
	if (argc < 4) {
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(EXIT_SUCCESS);
	}
	if (argc > 4) {
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");

		exit(EXIT_SUCCESS);
	}

	set_up(&board, &turn, num_rows, num_cols);
	play_game(board, turn, num_rows, num_cols, num_pieces);
	destroy_board(board, num_rows);
	return 0;
}

