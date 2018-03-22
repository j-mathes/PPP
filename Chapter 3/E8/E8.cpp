/*
Jared Mathes
2018-03-22
Chapter 3
Exercise 8 - Determine if the integer is odd or even
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will determine if the integer you input is odd or even.\n";
	cout << "Enter your integer.\n\n";
	cout << "> ";

	int number = 0;
	cin >> number;

	// test the number to determine if it is odd or even
	if (number % 2 == 0)
	{
		cout << "\nThe value " << number << " is even.\n\n";
	}
	else
	{
		cout << "\nThe value " << number << " is odd.\n\n";
	}

	keep_window_open();
	return 0;
}