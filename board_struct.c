#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "board_struct.h"
#include "input_val.h"


void make_board(Board* board) {
	int i, j;
	board->the_board = (char**)malloc(board->row * sizeof(char*));

	for (i = 0; i < (board->row); i++) {
		(board->the_board)[i] = (char*)malloc(board->col * sizeof(char));
		for (j = 0; j < (board->col); j++) {
			(board->the_board)[i][j] = '*';
		}
	}
}

void print_board(Board* board) {
	int i, j;
	for (i = 0; i < (board->row); i++) {
		printf("%d ", (board->row) - i - 1);
		for (j = 0; j < (board->col); j++) {
			printf("%c ", (board->the_board)[i][j]);
		}
		printf("\n");
	}
	printf(" ");
	for (j = 0; j < (board->col); j++) {
		printf("%d ", j);
	}
}