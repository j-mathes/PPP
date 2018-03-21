/*
	Jared Mathes
	2018-03-21
	Chapter 3
	Exercise 2 - Convert Miles to Kilometers
*/
#include "../../std_lib_facilities.h"

int main()
{
	const double miles_to_kilometers = 1.609;
	cout << "This program will convert miles to kilometers.\n";
	cout << "Enter in the number of miles.\n\n";
	cout << "> ";
	
	double miles = 0.0;
	cin >> miles;

	double kilometers = miles * miles_to_kilometers;

	cout << "\n" << miles << " miles = " << kilometers << " kilometers.\n\n";

	keep_window_open();
	return 0;
}