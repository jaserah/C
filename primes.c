#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/*this program takes a value from the user and finds the prime numbers between 
the user defined number and lists all the numbers within the range that are prime*/

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


/*this function checks whether or not the numbers within the
range are prime, using arrays, and then it prints the numbers
that are prime*/
void primes(int num) {
	int* numbers = (int*)malloc((num -1) * sizeof(int));
	int i, j;
	printf("The primes between 2 and %d are:\n", num);
    for (i = 0; i < (num -1); i++) {
        numbers[i] = i + 2;
        if (i == 0){
            printf("%d\n", numbers[i]);
            continue;
        }
		for (j = 0; j < i; j++) {
			if (numbers[i] % numbers[j] == 0) {
				break;
			}
			if (j==i-1){
                printf("%d\n", numbers[i]);
			}
		}
	}
    free(numbers);
}

/*this function asks the user to input a number to go to and
then checks if it's valid, and if not, then it loops until it
is valid input*/
int get_num() {
	int num_args_read;
	int num;
	do {
		printf("Enter a number greater than 1: ");
		num_args_read = scanf("%d", &num);
	} while ((!((assert_formatting(num_args_read, 1)) && (num > 1))));
	return num;
}

/*this function is where the other functions are called and it 
makes the program work*/
int main() {
	int num;
	num = get_num();
	primes(num);
	return 0;
}
