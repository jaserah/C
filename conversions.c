#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

/*this program asks the user to tell us whether they want to convert distance or tempurature,
then it asks for the user to input the temperature/distance along with its unit of measurement,
then it asks for the unit that the user wants the temperature/distance converted to.
Finally, the program converts the temperature/distance from one unit to the other*/


/*this function makes sure that there is nothing more written that what is asked for,
it does this by making sure that there is a new line (the enter button was clicked),
after the information needed by the computer has been entered*/
void assert_formatting(char choice) {
	//here, the 'enter key' is being defined so the computer knows what to look for
	char newLine = '\n';
	choice = scanf("%c", &newLine);
	/*if there is more in the input than there should have been, the enter key will
	not have been clicked when it should've been and it will give an error message and end the program*/
	if (newLine != '\n') {
		printf("Invalid formatting. Ending program.");
		exit(0);
	}
}

/* this is checking that the information inputted by the user is not a letter, but instead
a number. If it is a letter, then the program will print an error message and end the program*/
void numberNotLetter(double choice) {
	if (!(isalpha(choice))) {
		printf("Invalid formatting. Ending program.");
		exit(0);
	}
}
/*this is checking that the information inputted by the user is a letter, if it is not, then
the program will print an error message and end the program*/
void letterNotNumber(double choice) {
	if (isalpha(choice)) {
		printf("Invalid formatting. Ending program.");
		exit(0);
	}
}
/*this is making sure that the unit inputted by the user is a valid unit for tempurature and can 
be used in the program*/
void invalidTempType(char suffix) {
	/*it says that if the suffix/unit is not a 'F', 'f', 'C', 'c', 'K', 'k', but is a letter, then first check
	if there is too much input, with the 'assert formatting', if not, then the unit entered is not in the program and 
	it will print an error message and end the program*/
	if ((suffix != 'F') && (suffix != 'f') && (suffix != 'C') && (suffix != 'c') && (suffix != 'K') && (suffix != 'k') && (isalpha(suffix))) {
		assert_formatting(suffix);
		printf("%c is not a valid temperature type. Ending program.", suffix);
		exit(0);
	}
}
/*this function looks to see the unit inputted by the user is a valid unit for distance and can be
used in the program*/
void invalidDistType(char suffix) {
	/*it says that if the unit is not a F, f, I, i, Y, y, M, m, but is a letter, then first check if there is 
	too much input with the 'assert formatting' function, if not, then the unit entered is not in the program and 
	it will print an error message and end the program*/
	if ((suffix != 'F') && (suffix != 'f') && (suffix != 'I') && (suffix != 'i') && (suffix != 'Y') && (suffix != 'y') && (suffix != 'M') && (suffix != 'm') && (isalpha(suffix))) {
		assert_formatting(suffix);
		printf("%c is not a valid distance type. Ending program.", suffix);
		exit(0);
	}
}
/*this is essetially where all the conversions are done, it checks whether the user is using distance or temperature, 
then it looks for the unit that they want to use, and then mathematically converts from one unit to the unit that the
user wants to convert their number into*/
void conversion(char choice) {
	double temp;
	double dist;
	char suffix;
	char new_unit;
	double new_number;
	//this is where the program goes if the user wanted to use temperature and entered T
	if ((choice == 't') || (choice == 'T')) {
		printf("Enter the temperature followed by its suffix (F, C, or K): ");
		scanf("%lf %c", &temp, &suffix);
		//these are the diffent units that could have been the original units and below them is the math that is required to convert them to their new units
		if ((suffix == 'F') || (suffix == 'f') || (suffix == 'C') || (suffix == 'c') || (suffix == 'K') || (suffix == 'k')) {
			printf("Enter the new unit type (F, C, or K): ");
			scanf(" %c", &new_unit);
			//here we check to make sure that the unit inputted is valid 
			invalidTempType(new_unit);
			if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'C') || (new_unit == 'c'))) {
				new_number = (((temp - 32)*(5)) / (9));
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'K') || (new_unit == 'k'))) {
				new_number = ((((temp - 32)*(5)) / (9)) + 273.15);
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = temp;
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'C') || (suffix == 'c')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = (((temp * (9)) / (5)) + 32);
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'C') || (suffix == 'c')) && ((new_unit == 'C') || (new_unit == 'c'))) {
				new_number = temp;
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'C') || (suffix == 'c')) && ((new_unit == 'K') || (new_unit == 'k'))) {
				new_number = (temp + 273.15);
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'K') || (suffix == 'k')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = ((((temp - 273.15)*(9)) / (5)) + 32);
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'K') || (suffix == 'k')) && ((new_unit == 'C') || (new_unit == 'c'))) {
				new_number = (temp - 273.15);
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'K') || (suffix == 'k')) && ((new_unit == 'K') || (new_unit == 'k'))) {
				new_number = temp;
				printf("%.2lf%c is %.2lf%c", temp, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (suffix != (char)suffix) {
				printf("Invalid formatting. Ending program.");
				exit(0);
			}
		}
		/*we would go here if the original unit entered was not valid, and it would first check if there is more info entered
		than there should have been, then give an error message and end the program*/
		else if ((suffix != 'F') && (suffix != 'f') && (suffix != 'C') && (suffix != 'c') && (suffix != 'K') && (suffix != 'k') && (isalpha(suffix))) {
			assert_formatting(suffix);
			printf("%c is not a valid temperature type. Ending program.", suffix);
			exit(0);
		}
	}
	/*this is where the program would go if the user wanted to use distance, and entered D or d*/
	if ((choice == 'd') || (choice == 'D')) {
		printf("Enter the distance followed by its suffix (I,F,Y,M): ");
		scanf("%lf %c", &dist, &suffix);
		//here we check to make sure what is being entered is correct
		numberNotLetter(suffix);
		//these are the diffent units that could have been the original units and below them is the math that is required to convert them to their new units
		if ((suffix == 'F') || (suffix == 'f') || (suffix == 'I') || (suffix == 'i') || (suffix == 'Y') || (suffix == 'y') || (suffix == 'M') || (suffix == 'm')) {
			printf("Enter the new unit type (I,F,Y,M): ");
			scanf(" %c", &new_unit);
			//here we check to make sure the unit inputted is valid
			invalidDistType(new_unit);
			assert_formatting(new_unit);
			if (((suffix == 'I') || (suffix == 'i')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = (dist / 12);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'I') || (suffix == 'i')) && ((new_unit == 'Y') || (new_unit == 'y'))) {
				new_number = (dist / 36);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'I') || (suffix == 'i')) && ((new_unit == 'I') || (new_unit == 'i'))) {
				new_number = dist;
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'I') || (suffix == 'i')) && ((new_unit == 'M') || (new_unit == 'm'))) {
				new_number = (dist / 63360);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'I') || (new_unit == 'i'))) {
				new_number = (dist * 12);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'Y') || (new_unit == 'y'))) {
				new_number = (dist / 3);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = dist;
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'F') || (suffix == 'f')) && ((new_unit == 'M') || (new_unit == 'm'))) {
				new_number = (dist / 5280);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'Y') || (suffix == 'y')) && ((new_unit == 'I') || (new_unit == 'i'))) {
				new_number = (dist * 36);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'Y') || (suffix == 'y')) && ((new_unit == 'Y') || (new_unit == 'y'))) {
				new_number = dist;
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'Y') || (suffix == 'y')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = (dist * 3);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'Y') || (suffix == 'y')) && ((new_unit == 'M') || (new_unit == 'm'))) {
				new_number = (dist / 1760);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'M') || (suffix == 'm')) && ((new_unit == 'I') || (new_unit == 'i'))) {
				new_number = (dist * 63360);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'M') || (suffix == 'm')) && ((new_unit == 'M') || (new_unit == 'm'))) {
				new_number = dist;
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'M') || (suffix == 'm')) && ((new_unit == 'F') || (new_unit == 'f'))) {
				new_number = (dist * 5280);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (((suffix == 'M') || (suffix == 'm')) && ((new_unit == 'Y') || (new_unit == 'y'))) {
				new_number = (dist * 1760);
				printf("%.2lf%c is %.2lf%c", dist, toupper(suffix), new_number, toupper(new_unit));
			}
			else if (suffix != (char)suffix) {
				printf("Invalid formatting. Ending program.");
				exit(0);
			}
		}
		else if ((suffix != 'F') && (suffix != 'f') && (suffix != 'I') && (suffix != 'i') && (suffix != 'Y') && (suffix != 'y') && (suffix != 'M') && (suffix != 'm') && (isalpha(suffix))) {
			assert_formatting(suffix);
			printf("%c is not a valid distance type. Ending program.", suffix);
			exit(0);
		}
	}
	//the program would go here if the user neither inputted T, or D, therefore we cannot convert
	else if ((choice != 'T') && (choice != 't') && (choice != 'd') && (choice != 'D') && (isalpha(choice))) {
		printf("Unknown conversion type %c chosen. Ending Program.", choice);
		exit(0);
	}
}
//this is where the user picks whether they want to do tempurature or distance 
char choices() {
	char choice;
	printf("Pick the type of conversion that you would like to do.\n");
	printf("T or t for temperature\n");
	printf("D or d for distance\n");
	printf("Enter your choice: ");
	scanf("%c", &choice);
	return choice;
}
/*this is the main function in which all the variables used are defined and all the
functions are put together, to ask what conversion they would like to do, what the number
and unit of the original number and what they want to convert to, and then the program tells 
the user what the new number is with its new unit(this happens within conversion(choice)*/
int main() {
	char choice;
	choice = choices();
	numberNotLetter(choice);
	assert_formatting(choice);
	conversion(choice);
return 0;
	}
		