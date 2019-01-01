#include <stdio.h>
#include <string.h>

/*this program takes a binary input from the user from the commmand line, 
made up of 1s, Xs, and 0s, and then takes all the Xs within the input
and replaces them with 1s and 0s in order to give all possible 
combinations of the number with different numbers replacing the Xs.
this program  was made recursively*/

void bin_str(char* user_numbers, char* new_numbers);

/*this is the main function and it calls the bin_str function, which 
makes the whole program work. we put the given input from the user
into both, user_numbers and new_numbers because at first they are the
same and within the bin_str function, the new_numbers is changed*/
int main(int argc, char** argv) {
	bin_str(argv[1], argv[1]);
	return 0;
}

/*this function looks through the user_numbers and looks for 0s, 1s
and Xs. if user given value, user_numbers, is a 1, the 1 stays the same 
in new_numbers, as it does not have to be replaced. the same goes for 0s. 
if the user_number has an X, the position in new_numbers is replaced with a 
0 and a 1, and both are printed. this keeps happening until all the Xs are 
replaced by 1s and 0s and we have all possible combinations of binary numbers
printed*/
void bin_str(char* user_numbers, char* new_numbers) {
	if (*user_numbers == '\0') {
		printf("%s\n", new_numbers);
		return;
	}
	else if (*user_numbers == '1') {
		bin_str(user_numbers + 1, new_numbers);
	}
	else if (*user_numbers == '0') {
		bin_str(user_numbers + 1, new_numbers);
	}
	else if (*user_numbers == 'x') {
		*user_numbers = '0';
		bin_str(user_numbers + 1, new_numbers);
		*user_numbers = '1';
		bin_str(user_numbers + 1, new_numbers);
		*user_numbers = 'x';
	}
	return;
}