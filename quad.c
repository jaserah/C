#include <stdio.h>
#include <math.h>
/*this project asks the user to enter a, b and c and then uses the quadratic 
formula to solve for x. x could have one value, two values, or no values*/

/*here 'a' is defined by the user and returned to the main function*/
double numberA() {
	double numA;
	printf("Please enter a:\n");
	scanf("%lf", &numA);
	return numA;
}
/*here 'b' is defined by the user and returned to the main function*/
double numberB() {
	double numB;
	printf("Please enter b:\n");
	scanf("%lf", &numB);
	return numB;
}
/*here 'c' is defined by the sure and returned to the main function*/
double numberC() {
	double numC;
	printf("Please enter c:\n");
	scanf("%lf", &numC);
	return numC;
}
/*here all the work is done, the program takes the values of a, b and c and
puts them in the quadratic formula to see what x is*/
void quadratic(double a, double b, double c) {
	double x1;
	double x2;
	//this makes sure that a isn't 0 and that b is greater than 4*a*c, so there can be 2 solutions
	if ((a != 0) && (b > (sqrt(4 * a * c)))) {
		x1 = ((-1 * b) + (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);
		x2 = ((-1 * b) - (sqrt((pow(b, 2)) - (4 * a * c)))) / (2 * a);
		printf("There are 2 real solutions\n");
		printf("Solution 1: %.2lf\n", x1);
		printf("Solution 2: %.2lf", x2);
	}
	//this checks if b = 4*a*c, meaning the value under the square root is zero, this means there is 1 solution
	else if (b == (sqrt(4 * a * c))) {
		x1 = ((-1 * b) / (2 * a));
		printf("There is one real solution: %.2lf", x1);
	}
	//if it doesn't fit in either of the other categories, there are no solutions
	else {
		printf("There are no real solutions");
	}
}

/*this is given statement before the user inputs a, b and c*/
void given(){
	printf("Given a quadratic equation of the form  a*x^2 + b * x + c\n");
}

/*this is where all the information is put together and the functions are called to
ask and store the user's variables of a, b and c and then put them into the quadratic formula 
and print it all out to show the user*/
int main() {
	double a;
	double b;
	double c;
	given();
	a = numberA();
	b = numberB();
	c = numberC();
	quadratic(a, b, c);
return 0;
}