#include <stdlib.h>
#include <stdio.h>
#include "read_lines.h"

/*this program reads the lines in the entered file and then 
stores it into an array, and makes space for it so it can be 
used to print in the main function that was given*/

void read_lines(FILE* fp, char*** lines, int* num_lines) {
	char array[1000];
	int i = 0;
	int num = 0;

	while (fgets(array, 1000, fp) != NULL) {
		num++;
	}
	*lines = (char**)malloc(num * sizeof(char*));
	*num_lines = num;
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < num; i++) {
		(*lines)[i] = (char*)malloc(1000 * sizeof(char));
		fgets((*lines)[i], 1000, fp);
	}
}

