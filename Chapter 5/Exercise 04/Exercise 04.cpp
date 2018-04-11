// Jared Mathes
// 2018-04-10
// Chapter 5
// Exercise 04
// Celsius to Kelvin
// Check for valid input inside function


#include "../../std_lib_facilities.h"

class Bad_temperature {};	// type for reporting temperatures that are not acceptable

double ctok(double c)		// converts Celsius to Kelvin
{
	if (c <= -273.15)
	{
		throw Bad_temperature{};
	}
	else
	{
		double k = c + 273.15;
		return k;
	}
}

int main()
{
	double c = 0;			// declare input variable

	cout << "Enter a the number of degrees Celsius to convert to Kelvin >";

	try 
	{
		cin >> c;               // retrieve temperature to input variable

		double k = ctok(c);		// convert temperature
		cout << k << '/n';      // print out temperature
	}
	catch (Bad_temperature)
	{
		error(to_string(c) + " is an invalid temperature.");
	}

	return 0;
}