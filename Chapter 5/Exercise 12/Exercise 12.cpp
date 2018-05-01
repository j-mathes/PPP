// Jared Mathes
// 2018-05-01
// Chapter 5
// Exercise 12
// Bulls and Cows

#include "../../std_lib_facilities.h"


int main()
{
	vector<int> numbers_to_guess{ 1, 2, 3, 4 };
	vector<int> users_guess;
	bool correct = false;

	int bulls{ 0 };
	int cows{ 0 };

	while (!correct)
	{
		for (int i = 0; i < 4; ++i)
		{
			double value;
			cin >> value;

			users_guess.push_back(value);
		}


	}

	return 0;
}