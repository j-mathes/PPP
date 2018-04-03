/*
Jared Mathes
2018-04-02
Chapter 4
Exercise 02
Median
*/
#include "../../std_lib_facilities.h"

int main()
{
	vector<double> temps;
	
	for (double temp; cin>>temp;)
	{
		temps.push_back(temp);
	}

	// compute mean temperature
	double sum{ 0 };
	for (int x : temps) sum += x;
	cout << "Average temperature: " << sum / temps.size() << '\n';

	// compute median temperature
	sort(temps);

	for (int i{ 0 }; i<temps.size(); ++i)
	{
		cout << temps[i] << '\n';
	}

	if (temps.size() % 2 == 0 )
	{
		// case for even
		int index = (temps.size() / 2) - 1;
		double med = (temps[index] + temps[index + 1]) / 2;
		cout << "Median temperature: " << med  << '\n';
	}
	else
	{
		// case for odd
		cout << "Median temperature: " << temps[temps.size() / 2] << '\n';
	}

	return 0;
}