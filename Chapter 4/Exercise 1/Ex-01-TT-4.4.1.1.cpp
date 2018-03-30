/*
Jared Mathes
2018-03-29
Chapter 4
Exercise 01 - Try This 4.4.1.1
Currency Converter
*/
#include "../../std_lib_facilities.h"

int main()
{
	constexpr double yen_to_dollars { 0.012 };
	constexpr double euro_to_dollars { 1.59 };
	constexpr double pound_to_dollars{ 0.88 };

	double units_to_convert{ 0 };
	double dollars{ 0 };

	cout << "Would you like to convert 'Yen', 'Euro', or 'Pound' to Dollars? >";
	
	string conversion_type;
	cin >> conversion_type;

	if (conversion_type == "Yen" || conversion_type == "yen")
	{
		cout << "\n\nHow many Yen would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * yen_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
	} 
	else if (conversion_type == "Euro" || conversion_type == "euro")
	{
		cout << "\n\nHow many Euros would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * euro_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
	}
	else if (conversion_type == "Pound" || conversion_type == "pound")
	{
		cout << "\n\nHow many Pounds would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * pound_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
	}
	else
	{
		cout << "\n\nI'm sorry, I don't recognize that currency.\n\n";
	}

	return 0;
}