/*
	Jared Mathes
	2018-03-21
	Chapter 3
	Exercise 6 - Sort Three Integers
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will take three integer numbers and sort them.\n";
	cout << "Enter the first number.\n\n";
	cout << "> ";

	int first_number = 0;
	cin >> first_number;

	cout << "\nEnter the second number.\n\n";
	cout << "> ";

	int second_number = 0;
	cin >> second_number;

	cout << "\nEnter the third number.\n\n";
	cout << "> ";

	int third_number = 0;
	cin >> third_number;

	// sort the numbers
	int temp = 0;

	if (first_number > second_number)
	{
		temp = second_number;
		second_number = first_number;
		first_number = temp;
	}

	if (second_number > third_number)
	{
		temp = third_number;
		third_number = second_number;
		second_number = temp;

		if (first_number > second_number)
		{
			temp = second_number;
			second_number = first_number;
			first_number = temp;
		}
	}

	// display the output

	cout << "\n" << first_number << " , " << second_number << " , " << third_number << "\n\n";

	keep_window_open();
	return 0;
}
