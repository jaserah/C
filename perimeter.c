#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*this program calculates the perimeter of a polygon by taking the points
given in the binary file and finding the distance between the points and 
then using the distance formula to solve for the length of sides, and 
then eventually adding up all the side lengths to find the perimeter of 
the polygon*/

int main(int argc, const char* argv[]) {
	FILE* inFile = NULL;
	int num = 0;
	long read = 0;
	int* x_val = (int*)malloc(sizeof(int));
	int* y_val = (int*)malloc(sizeof(int));
	double x_distance = 0.00, y_distance = 0.00;
	double perimeter = 0.00;
	int i = 0;

	inFile = fopen(argv[1], "rb");
	read = fread(&num, sizeof(int), 1, inFile);
	x_val = (int*)realloc(x_val, num * sizeof(int));
	y_val = (int*)realloc(y_val, num * sizeof(int));
	while (read != 0){
		read = fread(&x_val[i], sizeof(int), 1, inFile);
		read = fread(&y_val[i], sizeof(int), 1, inFile);
		i++;
	}

	/*this section finds  all the distances and eventually puts it 
	together for the distance formula to find the length of a side
	and then adds it to the current added lengths of the other sides*/
	for (i = 0; i < num; i++) {
		x_distance = x_val[(i + 1) % num] - x_val[i];
		y_distance = y_val[(i + 1) % num] - y_val[i];
		perimeter = perimeter + sqrt(pow(x_distance, 2.0) + pow(y_distance, 2.0));
	}
	printf("The perimeter is %.2lf\n", perimeter);
	fclose(inFile);

	return 0;
}