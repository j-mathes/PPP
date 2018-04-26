// Jared Mathes
// 2018-04-26
// Chapter 5
// Exercise 9
// Add first n integers from input
// Add additional error checking and reporting

#include "../../std_lib_facilities.h"


int main()
{
	cout << "Enter the number of values you want to sum: ";

	int number_to_sum;
	cin >> number_to_sum;

	vector<int> values;

	cout << "\nPlease enter some integers (press | to stop): ";

	for (int value; cin >> value;)
	{
		values.push_back(value);
	}

	int sum = 0;

	if (values.size() < number_to_sum)
	{
		cout << "\nYou didn't enter in enough integers to sum.\n";
	}
	else
	{
		for (int i = 0; i < number_to_sum; ++i)
		{
			sum += values[i];
		}

		if (sum == (int)sum)
		{
			cout << "\nThe sum of the first " << number_to_sum << " numbers ( ";
			for (int i = 0; i < number_to_sum; ++i)
			{
				cout << values[i] << " ";
			}
			cout << ") is " << sum << ".\n";
		} 
		else
		{
			cout << "\nThe result cannot be represented as an integer.\n";
		}
	}

	return 0;
}