#ifndef INPUT_VAL_H
#define INPUT_VAL_H

void print_help();
void write(Board* board, int start_row, int start_col, int end_row, int end_col);
void horiz_line(Board* board, int row, int start_col, int end_col);
void vert_line(Board* board, int col, int start_row, int end_row);
void left_diag(Board* board, int start_col, int end_col, int start_row, int end_row);
void right_diag(Board* board, int start_col, int end_col, int start_row, int end_row);
void erase(Board* board, int row, int col);
void add_col(Board* board, int pos);
void get_input(Board* board);
void destroy_board(Board* board);

#endif