#include <stdio.h>

/*this program takes two matrices from the user and adds them together and then 
prints the new matrix that is created*/

void add_matrix(int A[100][100], int B[100][100], int rows, int columns);

/*this function asks the user to enter the matrices and then calls upon the function
to add them together*/
void collect_matrix(int rows, int columns) {
	int A[100][100];
	int B[100][100];
	int i = 0;
	int j = 0;
	printf("Enter Matrix A\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	printf("Enter Matrix B\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	add_matrix(A, B, rows, columns);
}

/*this function adds the two matrices together and then prints out the new matrix that was 
created*/
void add_matrix(int A[100][100], int B[100][100], int rows, int columns) {
	int i = 0;
	int j = 0;
	int C[100][100];
	printf("A + B =\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			C[i][j] = A[i][j] + B[i][j];
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}

/*this is where the user is asked to input the number of rows and columns and then it calls
the fuction to input the two matrices*/
int main() {
	int rows;
	int columns;

	printf("Please enter the number of rows: ");
	scanf("%d", &rows);
	printf("Please enter the number of columns: ");
	scanf("%d", &columns);
	collect_matrix(rows, columns);
	return 0;
}