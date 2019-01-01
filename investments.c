#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/*this program asks for information and solves for how much money a person could have when they retire.
it solves for how much money one has when paying off loans and investing at the same time and how much money 
one has when they pay off all their loans and then invest. the program then prints which one would give them more
retirement money, while making sure that the user inputs things in the correct format, and that they are giving enough
money to pay the loans off*/

void Warning(double owe_money);

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

/*in this function, it solves for the amount of retirement investment that the user will have if 
they pay their minimum loans while investing the rest of their money into retirement. the function returns
their investment*/
double pay_loan_and_invest(double max_money, double owe_money, double interest_rate, double min_payment, double age, double retire, double rate_return) {
	int months;
	double invest = 0;
	for (months = 0; (months < ((retire - age) * (12.0))); months++) {
		owe_money += (owe_money * (interest_rate/12.0));
		if (min_payment >= owe_money) {
			min_payment = owe_money;
		}
		owe_money -= min_payment;
		if (months > 0) {
			invest = ((max_money - min_payment) + (invest * (1.0 + (rate_return / 12.0))));
		}
		else {
			invest = invest + (max_money - min_payment);
		}
	}
	//Warning(owe_money);
	return invest;
}

double for_warning(double max_money, double owe_money, double interest_rate, double min_payment, double age, double retire, double rate_return) {
	int months;
	double invest = 0;
	for (months = 0; (months < ((retire - age) * (12.0))); months++) {
		owe_money += (owe_money * (interest_rate/12.0));
		if (min_payment >= owe_money) {
			min_payment = owe_money;
		}
		owe_money -= min_payment;
		if (months > 0) {
			invest = ((max_money - min_payment) + (invest * (1.0 + (rate_return / 12.0))));
		}
		else {
			invest = invest + (max_money - min_payment);
		}
	}
	return owe_money;
}


/*this function tells the user how much money they will have for their retirement if
they pay off all their loans and then invest for retirement after they have paid all their loans off*/
double pay_it_all(double max_money, double owe_money, double interest_rate, double retire, double age, double rate_return) {
	int months;
	double invest = 0.0;
	double pay = 0.0;
	for (months = 0; (months < ((retire - age) * (12.0))); months++) {
		invest = ((invest) * (1+(rate_return/12.0)));
		owe_money += (owe_money * (interest_rate/12.0));
		if (owe_money > max_money){
			pay = max_money;
		}
		if (owe_money < max_money){
			pay = owe_money;
		}
		owe_money -= pay;
		invest += max_money - pay;
	}
	return invest;
}

//checks to see if they have to pay loans while in retirement
void Warning(double owe_money){
	if (owe_money > 0){
		printf("Warning! After you retire you will still have $%.2lf in loans left.\n", owe_money);
	}
}

//asks the user to enter the amount of money they are willing to use for retirement/loans and checks if the input is valid, else it loops
double maxmoney() {
	int num_args_read;
	double max_money;
	do {
		printf("Enter how much money you will be putting towards loans/retirement each month: ");
		num_args_read = scanf("%lf", &max_money);
	} while (!(assert_formatting(num_args_read, 1) && (!(max_money <= 0))));
	return max_money;
}

//asks the user to enter the amount of loans they owe and checks if input is valid, else it loops
double owemoney() {
	int num_args_read;
	double owe_money;
	do {
		printf("Enter how much you owe in loans: ");
		num_args_read = scanf("%lf", &owe_money);
	} while (!(assert_formatting(num_args_read, 1) && (!(owe_money <= 0))));
	return owe_money;
}

//asks the user to enter the interest rate and checks if input is valid, else it loops
double interestrate() {
	int num_args_read;
	double interest_rate;
	do {
		printf("Enter the annual interest rate of the loans: ");
		num_args_read = scanf("%lf", &interest_rate);
	} while (!(assert_formatting(num_args_read, 1) && (!(interest_rate <= 0))));
	return interest_rate;
}

//asks the user to enter the minimum loan payment and checks if input is valid and money that they're willing to pay is larger than what they must pay
double minpayment(double max_money) {
	int num_args_read;
	double min_payment;
	do {
		printf("Enter your minimum monthly loan payment: ");
		num_args_read = scanf("%lf", &min_payment);
	} while (!(assert_formatting(num_args_read, 1) && (!(min_payment <= 0))));
	if (min_payment > max_money) {
		printf("You didn't set aside enough money to pay off our loans. Ending program.");
		exit(0);
	}
	return min_payment;
}

//asks the user to enter their current age and checks if input is valid
double agefirst() {
	int num_args_read;
	double age;
	do{
		printf("Enter your current age: ");
		num_args_read = scanf("%lf", &age);
	} while (!(assert_formatting(num_args_read, 1) && (!(age <= 0))));
	return age;
}

//asks the user to enter their retirement age and checks if input is valid
double retireage(double age) {
	int num_args_read;
	double retire;
	do {
		printf("Enter the age you plan to retire at: ");
		num_args_read = scanf("%lf", &retire);
	} while (!(assert_formatting(num_args_read, 1) && (!(retire < age))));
	return retire;
}

//asks the user to enter the investment rate return and checks if valid
double ratereturn() {
	int num_args_read;
	double rate_return;
	do {
		printf("Enter the annual rate of return you predict for your investments: ");
		num_args_read = scanf("%lf", &rate_return);
	} while (!(assert_formatting(num_args_read, 1) && (!(rate_return <= 0))));
	return rate_return;
}

/*prints the final print statement, depending on if they have more retirement money when paying loans and 
investing at the same time or if they have more retirement money when paying loans first and then 
putting in money to invest*/
void final_print(double max_money, double owe_money, double interest_rate, double min_payment, double age, double retire, double rate_return) {
	if (pay_loan_and_invest(max_money, owe_money, interest_rate, min_payment, age, retire, rate_return) > pay_it_all(max_money, owe_money, interest_rate, retire, age, rate_return)) {
		printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.", pay_loan_and_invest(max_money, owe_money, interest_rate, min_payment, age, retire, rate_return), pay_it_all(max_money, owe_money, interest_rate, retire, age, rate_return));
	}
	else {
		double pay_and_invest = pay_loan_and_invest(max_money, owe_money, interest_rate, min_payment, age, retire, rate_return);
		printf("You should apply all $%.2lf towards your loan before making any investments.\n If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.", max_money, pay_it_all(max_money, owe_money, interest_rate, retire, age, rate_return), pay_and_invest);
	}
}

/*this puts everything together and makes the variables equal to the functions that returns the value of the
variables and then prints the final print statement to give us the the amount of money that we will have during
retirement, using both senarios*/
int main() {
	double max_money;
	double owe_money;
	double interest_rate;
	double min_payment;
	double age;
	double retire;
	double rate_return;
	double warningnum;

	max_money = maxmoney();
	owe_money = owemoney();
	interest_rate = interestrate();
	min_payment = minpayment(max_money);
	age = agefirst();
	retire = retireage(age);
	rate_return = ratereturn();
	warningnum = for_warning(max_money, owe_money, interest_rate, min_payment, age, retire, rate_return);
	Warning(warningnum);
	final_print(max_money, owe_money, interest_rate, min_payment, age, retire, rate_return);
}