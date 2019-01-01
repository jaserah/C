#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

/*this program takes a seed and creates random points on a coordinate plane, then it uses
the points to estimate the value of pi by taking the number of points within a circle of radius 1, 
and dividing it by the total amount of points placed, this is also known as the monte carlo method */

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

//this function creates a random value with a low and high boundary
double random_num(double LO, double HI) {
	double number;
	number = LO + ((double)(rand()) / (((double)RAND_MAX) / (HI - LO)));
	return number;
}

/*this function takes the number of iterations that the user has entered and finds a random point, 
made up of x and y, and checks if it is within the circle of radius 1. The number of points within
the circle are then added up and returned*/
double pi(double iterations) {
	double x;
	double y;
	double runs;
	double in_circle = 0.0;
	double formula = 0.0;
	for(runs = 1; runs <= iterations; runs++) {
		x = random_num(-1.0, 1.0);
		y = random_num(-1.0, 1.0);
		formula = (pow(x, 2)) + (pow(y, 2));
		if (formula <= 1){
			in_circle = in_circle + 1;
		}
	}
	return in_circle;
}

//this function asks for the user to enter a seed
int seeds() {
	int num_args_read;
	int seed;
	do {
		printf("Enter the seed for the random number generator: ");
		num_args_read = scanf("%d", &seed);
	} while (!(assert_formatting(num_args_read, 1)));
	return seed;
}

//this function asks for the user to enter the number of iterations
double iterations_to_run() {
	int num_args_read;
	double iterations;
	do {
		printf("Enter the number of iterations to run: ");
		num_args_read = scanf("%lf", &iterations);
	} while (!(assert_formatting(num_args_read, 1) && (!(iterations <= 0))));
	return iterations;
}

/*this function takes the number of points in the circle, divides it
by the total number of iterations, and then multiplies it by four and prints
it as the value of pi.*/
void value(double iterations) {
	printf("The value of pi is %.5lf.", (4.0 * (pi(iterations))) / (iterations));
}

/*in this function, variables are declared and are put equal to the function that 
returns the variable's value. it puts all the functions together and makes it do 
what it should do, and find the value of pi*/
int main() {
	int seed;
	double iterations;
	seed = seeds();
	srand(seed);
	iterations = iterations_to_run();
	value(iterations);
	return 0;
}