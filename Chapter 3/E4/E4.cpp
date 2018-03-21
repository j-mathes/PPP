/*
	Jared Mathes
	2018-03-21
	Chapter 3
	Exercise 4 - Operations on two integers
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will take two integers and do some operations on them.\n";
	cout << "Enter in the first integer.\n\n";
	cout << "> ";

	int val1 = 0;
	cin >> val1;

	cout << "\nEnter in the second integer.\n\n";
	cout << "> ";

	int val2 = 0;
	cin >> val2;

	cout << "\nThe two integers are " << val1 << " and " << val2 << ".\n";

	// Smaller
	int smaller = (val1 <= val2) ? val1 : val2;
	cout << smaller << " is the smaller integer.\n";

	// Larger
	int larger = (val1 >= val2) ? val1 : val2;
	cout << larger << " is the larger integer.\n";

	// Sum
	int sum = val1 + val2;
	cout << val1 << " + " << val2 << " = " << sum << ".\n";

	// Difference
	int difference = larger - smaller;
	cout << larger << " - " << smaller << " = " << difference << ".\n";

	// Product
	int product = val1 * val2;
	cout << val1 << " * " << val2 << " = " << product << ".\n";

	// Ratio
	double ratio1 = (double)val1 / (double)val2;
	double ratio2 = (double)val2 / (double)val1;
	cout << "The ratio of " << val1 << " over " << val2 << " = " << ratio1 << ".\n";
	cout << "The ratio of " << val2 << " over " << val1 << " = " << ratio2 << ".\n\n";

	keep_window_open();
	return 0;
}