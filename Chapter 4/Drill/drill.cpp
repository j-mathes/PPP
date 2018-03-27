/*
Jared Mathes
2018-03-26
Chapter 4-8
Drill
*/
#include "../../std_lib_facilities.h"

int main()
{
	double number{ 0.0 };
	string units;
	double conversionFactor = 1.0;
	double largest;
	double smallest;
	bool firstTime = true;
	bool badInput = false;
	
	cout << "Please enter a number followed by the units (cm, in, ft, m) >";
	while (cin >> number >> units)
	{
		if (units == "cm" || units == "CM")
		{
			conversionFactor = 1.0;
		} 
		else if (units == "in" || units == "IN")
		{
			conversionFactor = 2.54;
		} 
		else if (units == "ft" || units == "FT")
		{
			conversionFactor = 12 * 2.54;
		}
		else if (units == "m" || units == "M")
		{
			conversionFactor = 100;
		}
		else
		{
			cout << "\n\n" << units << " is not a valid unit type.\n\n";
			badInput = true;
		}

		if (!badInput)
		{
			double convertedNumber = number * conversionFactor;

			if (firstTime)
			{
				smallest = convertedNumber;
				largest = convertedNumber;
				cout << number << " " << units << " is the smallest number so far.\n";
				cout << number << " " << units << " is the largest number so far.\n";
				firstTime = false;
			}
			cout << "\nThe number entered is " << number << " " << units << ".\n";

			if (convertedNumber < smallest)
			{
				smallest = convertedNumber;
				cout << number << " " << units << " is the smallest number so far.\n";
			}

			if (convertedNumber > largest)
			{
				largest = convertedNumber;
				cout << number << " " << units << " is the largest number so far.\n";
			}
		}

		badInput = false;
		
		cout << "\nPlease enter a number followed by the units (cm, in, ft, m) >";
	}
	
	return 0;
}