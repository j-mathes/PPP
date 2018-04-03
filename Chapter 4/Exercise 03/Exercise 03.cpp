/*
Jared Mathes
2018-04-03
Chapter 4
Exercise 03
Distance
*/
#include "../../std_lib_facilities.h"

int main()
{
	vector<double> distance;

	for (double temp; cin >> temp;)
	{
		distance.push_back(temp);
	}

	sort(distance);

	// sum of all distances 
	double sum{ 0 };
	for (int x : distance) sum += x;
	cout << "Total of all distances: " << sum << '\n';

	// smallest and largest distances
	cout << "Smallest distance between two cities: " << distance[0] << '\n';
	cout << "Largest distance between two cities: " << distance[distance.size() - 1] << '\n';

	// compute mean distance
	cout << "Mean distance between cities: " << sum / distance.size() << '\n';

	return 0;
}