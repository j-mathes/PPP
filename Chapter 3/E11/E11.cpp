/*
Jared Mathes
2018-03-22
Chapter 3
Exercise 11 - Counting coins
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will ask you how many of each coin you have and count them.\n";
	int pennies{ 0 };
	int nickels{ 0 };
	int dimes{ 0 };
	int quarters{ 0 };

	cout << "How many pennies do you have?\n\n";
	cout << "> ";
	cin >> pennies;

	cout << "How many nickels do you have?\n\n";
	cout << "> ";
	cin >> nickels;

	cout << "How many dimes do you have?\n\n";
	cout << "> ";
	cin >> dimes;

	cout << "How many quarters do you have?\n\n";
	cout << "> ";
	cin >> quarters;

	cout << "\nYou have " << pennies << " pennies.\n";
	cout << "You have " << nickels << " nickels.\n";
	cout << "You have " << dimes << " dimes.\n";
	cout << "You have " << quarters << " quarters.\n";

	int total_value = pennies + (nickels * 5) + (dimes * 10) + (quarters * 25);
	cout << "The value of all your coins is " << total_value << " cents.\n\n";

	keep_window_open();
	return 0;
}