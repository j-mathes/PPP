/*
Jared Mathes
2018-03-22
Chapter 3
Exercise 10 - Simple calculator	
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will take an operation and two operands and output the result.\n";
	cout << "Enter your operation and two numbers.\n\n";
	cout << "> ";

	string operation = "";
	double number_1 = 0.0;
	double number_2 = 0.0;

	cin >> operation;
	cin >> number_1;
	cin >> number_2;

	if (operation == "+" || operation == "plus")
	{
		cout << number_1 << " + " << number_2 << " = " << (number_1 + number_2) << ".\n\n";
	} 
	else if (operation == "-" || operation == "minus")
	{
		cout << number_1 << " - " << number_2 << " = " << (number_1 - number_2) << ".\n\n";
	}
	else if (operation == "*" || operation == "mul")
	{
		cout << number_1 << " * " << number_2 << " = " << (number_1 * number_2) << ".\n\n";
	}
	else if (operation == "/" || operation == "div")
	{
		cout << number_1 << " / " << number_2 << " = " << (number_1 / number_2) << ".\n\n";
	}
	else
	{
		cout << "\nI don't know that operator\n\n";
	}

	keep_window_open();
	return 0;
}