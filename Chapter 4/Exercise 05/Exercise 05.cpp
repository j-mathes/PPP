/*
Jared Mathes
2018-04-03
Chapter 4
Exercise 05
Simple Calculator
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "*****************\n";
	cout << "Simple calculator\n";
	cout << "*****************\n";
	cout << "\n";
	cout << "Enter two numbers and one of the four operators: +, -, *, /" << '\n';
	cout << "> ";

	double first_number{ 0 };
	double second_number{ 0 };
	char op;

	cin >> first_number;
	cin >> second_number;
	cin >> op;

	switch (op)
	{
	case '+':
		cout << "\n" << first_number << " + " << second_number << " = " << first_number + second_number << "\n";
		break;
	case '-':
		cout << "\n" << first_number << " - " << second_number << " = " << first_number - second_number << "\n";
		break;
	case '*':
		cout << "\n" << first_number << " * " << second_number << " = " << first_number * second_number << "\n";
		break;
	case '/':
		cout << "\n" << first_number << " / " << second_number << " = " << first_number / second_number << "\n";
		break;
	default:
		cout << "\n" << op << " isn't a valid operator.\n";
		break;
	}
	return 0;
}