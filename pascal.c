#include <stdio.h>

/*this program creates a pascal's triangle based on how many levels of Pascal's
Triangle the user wants to see, and then it displays the triangle*/

/*this function takes the number of levels and prints the actual triangle by using
a 2D array. First, it prints a 1 where the row and column number is equal, as well 
as when the column number is 0, because those are sides of the triangle that should
have 1s. Next, the function adds the values of the number above and the number to
the left and above in order to create the values of the places in between in the triangle.
Finally, it prints the whole thing*/
void pascal(int levels) {
	int pascal[28][28];
	int columns, rows;
	for (rows = 0; rows < levels; rows++) {
		for (columns = 0; columns <= rows; columns++) {
			if (columns == rows) {
				pascal[rows][columns] = 1;
			}
			else if (columns == 0) {
				pascal[rows][columns] = 1;
			}
			else {
				pascal[rows][columns] = pascal[rows - 1][columns - 1] + pascal[rows - 1][columns];
			}
			printf("%d ", pascal[rows][columns]);
		}
		printf("\n");
	}
}

/*this function asks the user to enter the number of levels that they want and then it calls
the function that does everything else and prints the whole thing*/
int main() {
	int levels;

	printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
	scanf("%d", &levels);
	pascal(levels);
	return 0;
}