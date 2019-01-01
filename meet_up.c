#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*this program creates 2 random points and places them on a board of rows x columns.
first, the two points are randomly selected and then the two points have to get closer 
together by randomly getting new points between its own rows/columns and the other point's. 
in the end, the points have to be on the same spot and must count the amount of moves it took, 
each time it iterates, in order to find an average number of rounds it takes to get to the same 
point*/

/*this is to make sure the formatting is correct and that the number of arguments needed is given,
as well as to make sure that there is nothing after what is being asked for*/
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

int move_piece(int row_P1, int row_P2, int column_P1, int column_P2);
int move_piece_more_than_5_sim(int row_P1, int row_P2, int column_P1, int column_P2);

//this function creates a random number for everytime the piece moves, after being initialized
int row_column_number(int lowerBound, int upperBound) {
	int number;
	number = (rand() % (upperBound - lowerBound + 1)) + lowerBound;

return number;
}

//this function creates a random number for the starting point of the piece
int random_number(int lowerBound, int upperBound) {
	int number;
	number = (rand() % (upperBound - lowerBound)) + lowerBound;

return number;
}

/*this function creates the starting point for the piece and then calls the function
to move it after the first time, and finally returns the average number of rounds it takes
to get the pieces on the same point*/
double one_sim(int simulations, int rows, int columns) {
	int row_P1;
	int column_P1;
	int row_P2;
	int column_P2;
	int sim;
	double rounds = 0;
	for (sim = 0; sim < simulations; sim++) {
		if (simulations <= 5) {
			printf("Simulation %d\n", sim);
			row_P1 = random_number(0, rows);
			column_P1 = random_number(0, columns);
			row_P2 = random_number(0, rows);
			column_P2 = random_number(0, columns);
			printf("Piece one starts at: %d, %d\n", row_P1, column_P1);
			printf("Piece two starts at: %d, %d\n", row_P2, column_P2);

			rounds = rounds + move_piece(row_P1, row_P2, column_P1, column_P2);
		}
		else {
			row_P1 = random_number(0, rows);
			column_P1 = random_number(0, columns);
			row_P2 = random_number(0, rows);
			column_P2 = random_number(0, columns);

			rounds = rounds + move_piece_more_than_5_sim(row_P1, row_P2, column_P1, column_P2);
		}
	}
	return (((double) rounds) / ((double) simulations));
}

/*this function takes the pieces and randomly moves them towards each other, depending on 
whether the rows or columns are the same, or neither, in the end, it returns the number of rounds that it went through*/
int move_piece(int row_P1, int row_P2, int column_P1, int column_P2) {
	int i = 0;
	for (i = 0; ((row_P1 != row_P2) || (column_P1 != column_P2)); i++) {
		int new_rowP1;
		int new_rowP2;
		int new_columnP1;
		int new_columnP2;
		//if the column values are the same and the first row # is larger than the second
		if ((column_P1 == column_P2) && (row_P1 > row_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1;
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2;
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, column_P1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, column_P2);
		}
		//if the column values are the same and the second row # is larger than the first
		if ((column_P1 == column_P2) && (row_P1 < row_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1;
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2;
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, column_P1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, column_P2);
		}
		//if row values are the same and the first column # is larger than the second
		if ((column_P1 > column_P2) && (row_P1 == row_P2)) {
			new_rowP1 = row_P1;
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2;
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, row_P1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, row_P2, new_columnP2);
		}
		//if row values are the same and the second column # is larger than the first
		if ((column_P1 < column_P2) && (row_P1 == row_P2)) {
			new_rowP1 = row_P1;
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2;
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, row_P1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, row_P2, new_columnP2);
		}
		//if the first row # is larger than the second, and the first column # is lager than the second
		if ((row_P1 > row_P2) && (column_P1 > column_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, new_columnP2);
		}
		//if the first row # is larger than the second and the second column # is larger than the first
		if((row_P1 > row_P2) && (column_P1 < column_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, new_columnP2);
		}
		//if the second row # is larger than the first and the first column # is larger than the second
		if((row_P1 < row_P2) && (column_P1 > column_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, new_columnP2);
		}
		//if the second row # is larger than the first and the second column # is larger than the first
		if((row_P1 < row_P2) && (column_P1 < column_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
			printf("First piece moves from %d,%d to %d,%d\n", row_P1, column_P1, new_rowP1, new_columnP1);
			printf("Second piece moves from %d,%d to %d,%d\n", row_P2, column_P2, new_rowP2, new_columnP2);
		}
		//sets the old column and row values equal to the new ones
		column_P2 = new_columnP2;
		column_P1 = new_columnP1;
		row_P1 = new_rowP1;
		row_P2 = new_rowP2;
}

	return i;
}

//does the same thing as move_piece, except doesnt print anything because it is more than 5 simulations
int move_piece_more_than_5_sim(int row_P1, int row_P2, int column_P1, int column_P2) {
	int i = 0;
	for (i = 0; ((row_P1 != row_P2) || (column_P1 != column_P2)); i++) {
		int new_rowP1;
		int new_rowP2;
		int new_columnP1;
		int new_columnP2;
		//if the column values are the same and the first row # is larger than the second
		if ((column_P1 == column_P2) && (row_P1 > row_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1;
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2;
		}
		//if the column values are the same and the second row # is larger than the first
		if ((column_P1 == column_P2) && (row_P1 < row_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1;
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2;
		}
		//if row values are the same and the first column # is larger than the second
		if ((column_P1 > column_P2) && (row_P1 == row_P2)) {
			new_rowP1 = row_P1;
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2;
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
		}
		//if row values are the same and the second column # is larger than the first
		if ((column_P1 < column_P2) && (row_P1 == row_P2)) {
			new_rowP1 = row_P1;
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2;
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
		}
		//if the first row # is larger than the second, and the first column # is lager than the second
		if ((row_P1 > row_P2) && (column_P1 > column_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
		}
		//if the first row # is larger than the second and the second column # is larger than the first
		if ((row_P1 > row_P2) && (column_P1 < column_P2)) {
			new_rowP1 = row_P1 - row_column_number(0, row_P1 - row_P2);
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2 + row_column_number(0, row_P1 - row_P2);
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
		}
		//if the second row # is larger than the first and the first column # is larger than the second
		if ((row_P1 < row_P2) && (column_P1 > column_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1 - row_column_number(0, column_P1 - column_P2);
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2 + row_column_number(0, column_P1 - column_P2);
		}
		//if the second row # is larger than the first and the second column # is larger than the first
		if ((row_P1 < row_P2) && (column_P1 < column_P2)) {
			new_rowP1 = row_P1 + row_column_number(0, row_P2 - row_P1);
			new_columnP1 = column_P1 + row_column_number(0, column_P2 - column_P1);
			new_rowP2 = row_P2 - row_column_number(0, row_P2 - row_P1);
			new_columnP2 = column_P2 - row_column_number(0, column_P2 - column_P1);
		}
		//sets the old column and row values equal to the new ones
		column_P2 = new_columnP2;
		column_P1 = new_columnP1;
		row_P1 = new_rowP1;
		row_P2 = new_rowP2;
	}

	return i;
}

//this function asks the user to enter a seed
int seeds() {
	int num_args_read;
	int seed;
	do {
		printf("Enter the seed for the random number generator: ");
		num_args_read = scanf("%d", &seed);
	} while (!(assert_formatting(num_args_read, 1)));
	return seed;
}

//this function asks the user to enter number of rows
int row() {
	int num_args_read;
	int rows;
	do {
		printf("Enter the number of rows on the board: ");
		num_args_read = scanf("%d", &rows);
	} while (!(assert_formatting(num_args_read, 1) && (!(rows <= 0))));
	return rows;
}

//this function asks the user to enter number of columns
int column() {
	int num_args_read;
	int columns;
	do {
		printf("Enter the number of columns on the board: ");
		num_args_read = scanf("%d", &columns);
	} while (!(assert_formatting(num_args_read, 1) && (!(columns <= 0))));
	return columns;
}

//this function asks the user to enter the number of simulations
int simulation() {
	int num_args_read;
	int simulations;
	do {
		printf("Enter the number of simulations to run: ");
		num_args_read = scanf("%d", &simulations);
	} while (!(assert_formatting(num_args_read, 1) && (!(simulations <= 0))));
	return simulations;
}

//this function returns the final print statement to say how many rounds it takes, on average
void pieces(double rounds, int rows, int columns) {
	printf("On average it takes %.2lf rounds on a board %d X %d for the pieces to meet.", rounds, rows, columns);
}

/*in this function, variables are declared and are put equal to the function that
returns the variable's value. it puts all the functions together and makes it do
what it should do, and print the average number of rounds it takes for the pieces 
to meet*/
int main() {
	int seed;
	int rows;
	int columns;
	int simulations;
	double rounds;

	seed = seeds();
	srand(seed);
	rows = row();
	columns = column();
	simulations = simulation();
	rounds = one_sim(simulations, rows, columns);
	pieces(rounds, rows, columns);
	return 0;
}