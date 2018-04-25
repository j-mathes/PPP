// Jared Mathes
// 2018-04-25
// Chapter 6
// Exercise 05
// Celsius / Fahrenheit conversion
// With estimation

#include "../../std_lib_facilities.h"

class Bad_temperature {};	// type for reporting temperatures that are not acceptable
class Bad_conversion_type {}; // type for reporting a conversion type that isn't acceptable

double ctof(double c)		// converts Celsius to Fahrenheit
{
	if (c < -273.15)
	{
		throw Bad_temperature{};
	}
	else
	{
		double f = 9.0/5*c+32;
		return f;
	}
}

double ftoc(double f)		// converts Fahrenheit to Celsius
{
	if (f < -459.67)
	{
		throw Bad_temperature{};
	}
	else
	{
		double c = (f - 32) * 5.0/9;
		return c;
	}
}

int main()
{
	char conversion_type;

	cout << "'C'elsius -> Fahrenheit or 'F'ahrenheit to Celsius? > ";

	cin >> conversion_type;

	double inp = 0;			// declare input variable

	try
	{
		switch (conversion_type)
		{
		case 'C':
		case 'c':
			cout << "\n\nEnter a the number of degrees Celsius to convert to Fahrenheit > ";

			try
			{
				cin >> inp;               // retrieve temperature to input variable

				double k = ctof(inp);		// convert temperature
				cout << '\n' << k << '\n';      // print out temperature
			}
			catch (Bad_temperature)
			{
				error(to_string(inp) + " is an invalid temperature.");
			}
			break;

		case 'F':
		case 'f':
			cout << "\n\nEnter a the number of degrees Fahrenheit to convert to Celsius > ";

			try
			{
				cin >> inp;               // retrieve temperature to input variable

				double c = ftoc(inp);		// convert temperature
				cout << '\n' << c << '\n';      // print out temperature
			}
			catch (Bad_temperature)
			{
				error(to_string(inp) + " is an invalid temperature.");
			}
			break;

		default:
			throw Bad_conversion_type{};
			break;
		}
	}
	catch (Bad_conversion_type)
	{
		error(to_string(conversion_type) + " is an invalid conversion.");
	}

	return 0;
}