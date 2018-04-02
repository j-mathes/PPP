/*
Jared Mathes
2018-03-29
Chapter 4
Exercise 01 - Try This 4.4.1.3
Currency Converter with switch statements
*/
#include "../../std_lib_facilities.h"

int main()
{
	constexpr double yen_to_dollars { 0.012 };
	constexpr double euro_to_dollars { 1.59 };
	constexpr double pound_to_dollars{ 0.88 };

	double units_to_convert{ 0 };
	double dollars{ 0 };

	int conversion_indicator{ 0 };

	cout << "1-Would you like to convert 'Yen', 'Euro', or 'Pound' to Dollars? >";
	
	string conversion_type;
	cin >> conversion_type;


	if (conversion_type == "Yen" || conversion_type == "yen")
	{
		conversion_indicator = 1;
	} 
	else if (conversion_type == "Euro" || conversion_type == "euro")
	{
		conversion_indicator = 2;
	}
	else if (conversion_type == "Pound" || conversion_type == "pound")
	{
		conversion_indicator = 3;
	}


	switch (conversion_indicator)
	{
	case 1:
		cout << "\n\nHow many Yen would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * yen_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
		break;
	case 2:
		cout << "\n\nHow many Euros would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * euro_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
		break;
	case 3:
		cout << "\n\nHow many Pounds would you like to convert? >";
		cin >> units_to_convert;
		dollars = units_to_convert * pound_to_dollars;
		cout << "\n\nThat converts to $" << dollars << ".\n\n";
		break;
	default:
		cout << "\n\nI'm sorry, I don't recognize that currency.\n\n";
		break;
	}

	return 0;
}