/*
Jared Mathes
2018-03-22
Chapter 3
Exercise 9 - spell out entered number
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will spell out the number you enter.\n";
	cout << "Enter your integer.\n\n";
	cout << "> ";

	int number = 0;
	cin >> number;

	switch (number)
	{
	case 0:
		cout << "\nZero.\n\n";
		break;

	case 1:
		cout << "\nOne.\n\n";
		break;

	case 2:
		cout << "\nTwo.\n\n";
		break;

	case 3:
		cout << "\nThree.\n\n";
		break;

	case 4:
		cout << "\nFout.\n\n";
		break;

	default:
		cout << "\nThat's not a number I know.\n\n";
		break;
	}

	keep_window_open();
	return 0;
}