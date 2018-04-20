// Jared Mathes
// 2018-04-19
// Chapter 5
// Exercise 05
// Celsius to Kelvin
// Add Kelvin to Celsius

#include "../../std_lib_facilities.h"

class Bad_temperature {};	// type for reporting temperatures that are not acceptable
class Bad_conversion_type {}; // type for reporting a conversion type that isn't acceptable

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

double ktoc(double k)		// converts Kelvin to Celsius
{
	if (k < 0)
	{
		throw Bad_temperature{};
	}
	else
	{
		double c = k - 273.15;
		return c;
	}
}

int main()
{
	char conversion_type;

	cout << "'C'elsius -> Kelvin or 'K'elvin to Celsius? > ";
	
	cin >> conversion_type;

	double inp = 0;			// declare input variable

	try
	{
		switch (conversion_type)
		{
		case 'C':
		case 'c':
			cout << "\n\nEnter a the number of degrees Celsius to convert to Kelvin > ";
	
			try
			{
				cin >> inp;               // retrieve temperature to input variable
	
				double k = ctok(inp);		// convert temperature
				cout << '\n' << k << '\n';      // print out temperature
			}
			catch (Bad_temperature)
			{
				error(to_string(inp) + " is an invalid temperature.");
			}
			break;

		case 'K':
		case 'k':
			cout << "\n\nEnter a the number of degrees Kelvin to convert to Celsius > ";
	
			try
			{
				cin >> inp;               // retrieve temperature to input variable
	
				double c = ktoc(inp);		// convert temperature
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