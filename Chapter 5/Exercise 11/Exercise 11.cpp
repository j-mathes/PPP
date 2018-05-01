// Jared Mathes
// 2018-05-01
// Chapter 5
// Exercise 11
// write out first n values of the Fibonacci series.

#include "../../std_lib_facilities.h"


int main()
{
	cout << "Expand the Fibonacci series to how many values? > ";

	int series_number{ 0 };
	cin >> series_number;

	if (series_number > 0)
	{
		int prev_1{ 0 };
		int prev_2{ 0 };
		int total{ 0 };

		for (int i = 0; i < series_number; ++i)
		{
			if (i == 0)
			{
				total = 1;
			}
			else
			{
				total = prev_1 + prev_2;
			}
			
			if (total > 0)
			{
				cout << total << '\n';
				prev_2 = prev_1;
				prev_1 = total;
			}
			else
			{
				cout << "Fibonacci series overflows an int after " << i << " iterations.\n";
				cout << "The largest Fibonacci number that fits in an int is " << prev_1 << ".\n";
				break;
			}

		}
	}
	else
	{
		error("You need to enter an integer value greater than zero.");
	}

	return 0;
}