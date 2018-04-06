// Jared Mathes
// 2018-04-05
// Chapter 4
// Exercise 16
// Find the mode of a set of integers

#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter a series of positive integers.\n";

	vector<int> series;

	for (int number; cin >> number;)
	{
		series.push_back(number);
	}

	sort(series);

	int mode_candidate = series[0];
	int mode_integer = mode_candidate;
	int temp_count{ 1 };
	int mode_count{ 1 };
	int x;

	for (x = 1 ; x < series.size(); ++x)
	{
		if (series[x] == mode_candidate)
		{
			++temp_count;
		}
		else
		{
			if (temp_count > mode_count)
			{
				mode_count = temp_count;
				mode_integer = mode_candidate;
			}

			temp_count = 1;
			mode_candidate = series[x];
		}
	}

	// there has to be a way to move this inside the loop.  do-while?
	if (temp_count > mode_count)
	{
		mode_count = temp_count;
		mode_integer = mode_candidate;
	}

	cout << "\nThe mode is : " << mode_integer << '\n';

	return 0;
}