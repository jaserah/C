#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "Board.h"
#include "input_val.h"
#include "board_struct.h"

bool assert_formatting(int num_args_read, int num_agrs_needed) {
	char newLine = '\n';
	bool right_format = true;
	if (num_args_read != num_agrs_needed) {
		right_format = false;
	}
	do {
		scanf("%c", &newLine);
		if (!isspace(newLine)) {
			right_format = false;
		}
	} while (newLine != '\n');
	return right_format;
}

void print_help(Board* board) {

	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
	print_board(board);
}

void write(Board* board, int start_row, int start_col, int end_row, int end_col) {
	if (start_row == end_row) {
		horiz_line(board, start_row, start_col, end_col);
	}
	else if (start_col == end_col) {
		vert_line(board, start_col, start_row, end_row);
	}
	else if (((end_row - start_row) / (end_col - start_col)) == 1) {
		left_diag(board, start_col, end_col, start_row, end_row);
	}
	else if (((end_row - start_row) / (end_col - start_col)) == -1) {
		right_diag(board, start_col, end_col, start_row, end_row);
	}
	else if ((start_row > board->row - 1) || (start_col > board->col - 1) || (end_row > board->row - 1) || (end_col > board->col - 1) || (start_row < 0) || (start_col < 0) || (end_row < 0) || (end_col < 0)) {
		printf("Improper draw command.\n");
		print_board(board);
	}
	else {
		printf("Cannot draw the line as it is not straight.\n");
		print_board(board);
	}
}

void horiz_line(Board* board, int row, int start_col, int end_col) {
	int i;
	if (start_col < end_col) {
		for (i = start_col; i <= end_col; i++) {
			if (((board->the_board)[board->col - row - 1][i] != '*') && ((board->the_board)[board->col - row - 1][i] != '-')) {
				(board->the_board)[board->col - row - 1][i] = '+';
			}
			else {
				(board->the_board)[board->col - row - 1][i] = '-';
			}
		}
	}
	else {
		for (i = end_col; i <= start_col; i++) {
			if (((board->the_board)[board->col - row - 1][i] != '*') && ((board->the_board)[board->col - row - 1][i] != '-')) {
				(board->the_board)[board->col - row - 1][i] = '+';
			}
			else {
				(board->the_board)[board->col - row - 1][i] = '-';
			}
		}
	}
	print_board(board);
}


void vert_line(Board* board, int col, int start_row, int end_row) {
	int i;
	if (start_row < end_row) {
		for (i = board->col - end_row - 1; i <= board->col - start_row - 1; i++) {
			if (((board->the_board)[i][col] != '*') && ((board->the_board)[i][col] != '|')) {
				(board->the_board)[i][col] = '+';
			}
			else {
				(board->the_board)[i][col] = '|';
			}
		}
	}
	else {
		for (i = board->col - start_row - 1; i <= board->col - end_row - 1; i++) {
			if (((board->the_board)[i][col] != '*') && ((board->the_board)[i][col] != '|')) {
				(board->the_board)[i][col] = '+';
			}
			else {
				(board->the_board)[i][col] = '|';
			}
		}
	}
	print_board(board);
}

void left_diag(Board* board, int start_col, int end_col, int start_row, int end_row) {
	int i, j;

	if (start_row < end_row) {
		j = board->col - start_row - 1;
		for (i = start_col; i <= end_col; i++) {
			if (((board->the_board)[j][i] != '*') && ((board->the_board)[j][i] != '/')) {
				(board->the_board)[j][i] = '+';
			}
			else {
				(board->the_board)[j][i] = '/';
			}
			j--;
		}
	}
	else {
		j = board->col - end_row - 1;
		for (i = end_col; i <= start_col; i++) {
			if (((board->the_board)[j][i] != '*') && ((board->the_board)[j][i] != '/')) {
				(board->the_board)[j][i] = '+';
			}
			else {
				(board->the_board)[j][i] = '/';
			}
			j--;
		}
	}
	print_board(board);
}

void right_diag(Board* board, int start_col, int end_col, int start_row, int end_row) {
	int i, j;

	if (start_row < end_row) {
		j = board->col - end_row - 1;
		for (i = end_col; i <= start_col; i++) {
			if (((board->the_board)[j][i] != '*') && ((board->the_board)[j][i] != '\\')) {
				(board->the_board)[j][i] = '+';
			}
			else {
				(board->the_board)[j][i] = '\\';
			}
			j++;
		}
	}
	else {
		j = board->col - start_row - 1;
		for (i = start_col; i <= end_col; i++) {
			if (((board->the_board)[j][i] != '*') && ((board->the_board)[j][i] != '\\')) {
				(board->the_board)[j][i] = '+';
			}
			else {
				(board->the_board)[j][i] = '\\';
			}
			j++;
		}
	}
	print_board(board);
}


void erase(Board* board, int row, int col) {
	(board->the_board)[board->col - row - 1][col] = '*';
	print_board(board);
}


void add_row(Board* board, int pos) {
	int i = 0;
	int j = 0;
	(board->row) += 1;
	(board->the_board) = (char**)realloc((board->the_board), (board->row) * sizeof(char*));
	for (i = 0; i < board->row; i++) {
		(board->the_board)[i] = (char*)realloc((board->the_board)[i], (board->col) * sizeof(char));
	}
	for (i = board->row - 1; i > board->row - pos - 1; i--) {
		for (j = 0; j < board->col; j++) {
			(board->the_board)[i][j] = (board->the_board)[i - 1][j];
		}
	}
	for (j = 0; j < board->col; j++) {
		board->the_board[board->row - pos - 1][j] = '*';
	}
	print_board(board);
}


void add_col(Board* board, int pos) {
	int i = 0;
	int j = 0;
	(board->col) += 1;
	for (i = 0; i < board->row; i++) {
		(board->the_board)[i] = (char*)realloc((board->the_board)[i], ((board->col) * sizeof(char)));
	}
	for (i = 0; i < (board->row); i++) {
		for (j = (board->col) - 1; j > pos; j--) {
			(board->the_board)[i][j] = (board->the_board)[i][j - 1];
		}
		(board->the_board)[i][pos] = '*';
	}
	print_board(board);
}

void resize(Board* board, int new_row, int new_col) {
	int i = 0;
	int j = 0;
	int rows = board->row;
	int cols = board->col;
	char** temp_arr;
	temp_arr = (char**)malloc(rows * sizeof(char*));

	for (i = 0; i < rows; i++) {
		temp_arr[i] = (char*)malloc(cols * sizeof(char));
		for (j = 0; j < (cols); j++) {
			temp_arr[i][j] = (board->the_board)[i][j];
		}
	}
	(board->row) = new_row;
	(board->col) = new_col;
	(board->the_board) = (char**)realloc((board->the_board), ((board->row) * sizeof(char*)));
	for (i = 0; i < board->row; i++) {
		(board->the_board)[i] = (char*)realloc((board->the_board)[i], ((board->col) * sizeof(char)));
		for (j = 0; j < board->col; j++) {
			(board->the_board)[i][j] = '*';
		}
	}
	if ((rows < board->row) && (cols < board->col)) {
		for (i = 0; i < rows; i++) {
			for (j = 0; j < cols; j++) {
				(board->the_board)[(board->row) - i - 1][j] = temp_arr[rows - i - 1][j];
			}
		}
	}
	if ((rows < board->row) && (cols > board->col)) {
		for (i = 0; i < rows; i++) {
			for (j = 0; j < board->col; j++) {
				(board->the_board)[(board->row) - i - 1][j] = temp_arr[rows - i - 1][j];
			}
		}
	}
	if ((rows > board->row) && (cols < board->col)) {
		for (i = 0; i < board->row; i++) {
			for (j = 0; j < cols; j++) {
				(board->the_board)[(board->row) - i - 1][j] = temp_arr[rows - i - 1][j];
			}
		}
	}
	if ((rows > board->row) && (cols > board->col)) {
		for (i = 0; i < board->row; i++) {
			for (j = 0; j < board->col; j++) {
				(board->the_board)[(board->row) - i - 1][j] = temp_arr[rows - i - 1][j];
			}
		}
	}
	print_board(board);
}

void delete_col(Board* board, int pos) {
	int i = 0;
	int j = 0;
	board->col -= 1;
	for (i = 0; i < board->row; i++) {
		board->the_board[i] = (char*)realloc(board->the_board[i], (board->col) * sizeof(char));
	}
	for (i = 0; i < board->row; i++) {
		for (j =pos; j < board->col; j++) {
			board->the_board[i][j] = board->the_board[i][j + 1];
		}
	}
	print_board(board);
}

void delete_row(Board* board, int pos) {
	int i = 0;
	int j = 0;
	board->row -= 1;
	board->the_board = (char**)realloc(board->the_board, (board->row) * sizeof(char*));
	for (i = 0; i < board->row; i++) {
		board->the_board[i] = (char*)realloc(board->the_board[i], (board->col) * sizeof(char));
	}
	for (i = board->row - pos; i < board->row; i++) {
		for (j = 0; j < board->col; j++) {
			board->the_board[i][j] = board->the_board[i + 1][j];
		}
	}
	print_board(board);
}

void get_input(Board* board) {
	char command = 0;
	int start_row;
	int start_col;
	int end_row;
	int end_col;
	char rowcol;
	int pos;
	int new_row;
	int new_col;
	int num_args_read;

	while (command != 'q') {
		printf("\nEnter your command: ");
		num_args_read = scanf(" %c", &command);
		if (command == 'h') {
			if ((!assert_formatting(num_args_read, 1))) {
				printf("Unrecognized command. Type h for help.\n");
				print_board(board);
			}
			else {
				print_help(board);
			}
		}
		else if (command == 'w') {
			num_args_read = scanf(" %d %d %d %d", &start_row, &start_col, &end_row, &end_col);
			if ((end_col > board->col) || (start_col < 0)) {
				printf("Improper draw command.\n");
				print_board(board);
			}
			else if (assert_formatting(num_args_read, 4)) {
				write(board, start_row, start_col, end_row, end_col);
			}
			else {
				printf("Improper draw command.\n");
				print_board(board);
			}
		}
		else if (command == 'e') {
			scanf("%d %d", &start_row, &start_col);
			if ((start_row >= board->row) || (start_col >= board->col) || (start_row < 0) || (start_col < 0)) {
				printf("Improper erase command.\n");
				print_board(board);
			}
			else {
				erase(board, start_row, start_col);
			}
		}
		else if (command == 'a') {
			num_args_read = scanf(" %c %d", &rowcol, &pos);
			if (!assert_formatting(num_args_read, 2)) {
				printf("Improper add command.\n");
				print_board(board);
			}
			else if (rowcol == 'r') {
				if ((pos > board->row)|| (pos < 0)) {
					printf("Improper add command.\n");
					print_board(board);
				}
				else {
					add_row(board, pos);
				}
			}
			else if (rowcol == 'c') {
				if ((pos > board->col) || (pos < 0)) {
					printf("Improper add command.\n");
					print_board(board);
				}
				else {
					add_col(board, pos);
				}
			}
		}
		else if (command == 'r') {
			scanf(" %d %d", &new_row, &new_col);
			if ((new_row < 1) || (new_col < 0)) {
				printf("Improper resize command.\n");
				print_board(board);
			}
			else {
				resize(board, new_row, new_col);
			}
		}
		else if (command == 'd') {
			num_args_read = scanf(" %c %d", &rowcol, &pos);
			if (!assert_formatting(num_args_read, 2)) {
				printf("Improper delete command.\n");
				print_board(board);
			}
			else if (rowcol == 'c') {
				if ((pos < 0) || (pos >= (board->col))) {
					printf("Improper delete command.\n");
					print_board(board);
				}
				else {
					delete_col(board, pos);
				}
			}
			else if (rowcol == 'r') {
				if ((pos < 0) || (pos >= (board->row))) {
					printf("Improper delete command.\n");
					print_board(board);
				}
				else {
					delete_row(board, pos);
				}
			}
		}
		else if (command == 'u') {
			printf("Unrecognized command. Type h for help.\n");
			print_board(board);
			printf("Enter your command: ");
			exit(0);
		}
	}
	if (command == 'q') {
		if (!(assert_formatting(num_args_read, 1))) {
			printf("Unrecognized command. Type h for help.\n");
			print_board(board);
			printf("Enter your command: ");
		}
		else {
			destroy_board(board);
		}
	}
}

void destroy_board(Board* board) {
	int i;
	for (i = 0; i < (board->row); i++) {
		free((board->the_board)[i]);
	}
	free(board->the_board);
	exit(0);
}