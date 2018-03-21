/*
	Jared Mathes
	2018-03-21
	Chapter 3
	Exercise 5 - Operations on two doubles
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will take two double precision floating point numbers and do some operations on them.\n";
	cout << "Enter in the first number.\n\n";
	cout << "> ";

	double val1 = 0.0;
	cin >> val1;

	cout << "\nEnter in the second number.\n\n";
	cout << "> ";

	double val2 = 0.0;
	cin >> val2;

	cout << "\nThe two numbers are " << val1 << " and " << val2 << ".\n";

	// Smaller
	double smaller = (val1 <= val2) ? val1 : val2;
	cout << smaller << " is the smaller integer.\n";

	// Larger
	double larger = (val1 >= val2) ? val1 : val2;
	cout << larger << " is the larger integer.\n";

	// Sum
	double sum = val1 + val2;
	cout << val1 << " + " << val2 << " = " << sum << ".\n";

	// Difference
	double difference = larger - smaller;
	cout << larger << " - " << smaller << " = " << difference << ".\n";

	// Product
	double product = val1 * val2;
	cout << val1 << " * " << val2 << " = " << product << ".\n";

	// Ratio
	double ratio1 = val1 / val2;
	double ratio2 = val2 / val1;
	cout << "The ratio of " << val1 << " over " << val2 << " = " << ratio1 << ".\n";
	cout << "The ratio of " << val2 << " over " << val1 << " = " << ratio2 << ".\n\n";

	keep_window_open();
	return 0;
}