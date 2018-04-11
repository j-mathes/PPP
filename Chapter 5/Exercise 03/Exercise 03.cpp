// Jared Mathes
// 2018-04-10
// Chapter 5
// Exercise 03
// Celsius to Kelvin
// Check for valid input


#include "../../std_lib_facilities.h"

double ctok(double c)		// converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}

int main()
{
	double c = 0;			// declare input variable

	cout << "Enter a the number of degrees Celsius to convert to Kelvin >";

	cin >> c;               // retrieve temperature to input variable

	if ( c <= -273.15)
	{
		error(to_string(c) + " is an invalid temperature.");
	}

	double k = ctok(c);		// convert temperature
	cout << k << "\n";      // print out temperature

	return 0;
}