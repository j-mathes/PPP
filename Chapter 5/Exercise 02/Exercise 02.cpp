// Jared Mathes
// 2018-04-10
// Chapter 5
// Exercise 02
// Debugging the Celsius to Kelvin program
// List of errors:
// 1 - missing #include for library
// 2 - missing ; from return in ctok function
// 3 - return type is int when double is expected
// 4 - wrong input variable is being used
// 5 - call to ctok has a string "c" as a parameter instead of the variable c
// 6 - cout is capitalized
// 7 - main doesn't return a value

#include "../../std_lib_facilities.h"

double ctok(double c)		// converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}

int main()
{
	double c = 0;			// declare input variable
	cin >> c;               // retrieve temperature to input variable
	double k = ctok(c);		// convert temperature
	cout << k << '/n';      // print out temperature
	
	return 0;
}