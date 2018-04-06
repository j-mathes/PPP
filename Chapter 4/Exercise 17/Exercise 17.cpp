// Jared Mathes
// 2018-04-06
// Chapter 4
// Exercise 17
// Find the min, max, and mode of a set of strings

#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter a series of strings (ctrl+Z to end).\n";

	vector<string> series;

	for (string a_string; cin >> a_string;)
	{
		series.push_back(a_string);
	}

	sort(series);

	string mode_candidate = series[0];
	string mode_string = mode_candidate;
	int temp_count{ 1 };
	int mode_count{ 1 };
	int x;

	for (x = 1; x < series.size(); ++x)
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
				mode_string = mode_candidate;
			}

			temp_count = 1;
			mode_candidate = series[x];
		}
	}

	// there has to be a way to move this inside the loop.  do-while?
	if (temp_count > mode_count)
	{
		mode_count = temp_count;
		mode_string = mode_candidate;
	}

	cout << "\nThe min is  : " << series[0] << '\n';
	cout << "The max is  : " << series[series.size() - 1] << '\n';
	cout << "The mode is : " << mode_string << '\n\n';

	return 0;
}