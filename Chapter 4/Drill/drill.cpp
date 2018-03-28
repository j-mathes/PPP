/*
Jared Mathes
2018-03-26
Chapter 4-11
Drill
*/
#include "../../std_lib_facilities.h"

int main()
{
	vector<double> numbers;
	double number{ 0.0 };
	string units;
	double conversionFactor{ 1.0 };
	double largest;
	double smallest;
	bool firstTime{ true };
	bool badInput{ false };
	int valuesEntered{ 0 };
	double sum{ 0 };
	
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
			valuesEntered++;
			double convertedNumber = number * conversionFactor;
			sum += convertedNumber;

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

			cout << "\nThe smallest number (converted to meters) is " << smallest / 100 << " m.\n";
			cout << "The largest number (converted to meters) is " << largest / 100 << " m.\n";
			cout << "The number of values entered is " << valuesEntered << ".\n";
			cout << "The sum of all values entered is " << sum / 100 << " m.\n";

			numbers.push_back(convertedNumber);
		}

		badInput = false;
		
		cout << "\nPlease enter a number followed by the units (cm, in, ft, m) >";
	}
	
	cout << "\n";
	sort(numbers);

	for (size_t x{ 0 }; x < numbers.size(); ++x)
	{
		cout << "\n" << numbers[x] / 100 << " meters.";
	}

	cout << "\n";

	return 0;
}