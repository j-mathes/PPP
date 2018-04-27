// Jared Mathes
// 2018-04-27
// Chapter 5
// Exercise 10
// Add first n doubles from input
// Vector of differences between adjacent values

#include "../../std_lib_facilities.h"


int main()
{
	cout << "Enter the number of values you want to sum: ";

	int number_to_sum;
	cin >> number_to_sum;

	vector<double> values;

	cout << "\nPlease enter some double precision numbers (press | to stop): ";

	for (double value; cin >> value;)
	{
		values.push_back(value);
	}

	double sum = 0;

	if (values.size() < number_to_sum)
	{
		cout << "\nYou didn't enter in enough numbers to sum.\n";
	}
	else
	{
		cout << "\nThe sum of the first " << number_to_sum << " numbers ( ";
		for (int i = 0; i < number_to_sum; ++i)
		{
			sum += values[i];
			cout << values[i] << " ";
		}
		cout << ") is " << sum << ".\n\n";

		vector<double> differences;
		for (int i = 1; i < values.size(); ++i)
		{
			differences.push_back(values[i] - values[i - 1]);
		}

		cout << "The difference between adjacent values:\n";
		for (int i = 0; i < differences.size(); ++i)
		{
			cout << values[i + 1] << " - " << values[i] << " = " << differences[i] << '\n';
		}
		cout << '\n';
	}

	return 0;
}