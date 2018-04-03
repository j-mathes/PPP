/*
Jared Mathes
2018-04-03
Chapter 4
Exercise 04
Guessing Game
*/
#include "../../std_lib_facilities.h"

int main()
{
	int number_to_guess{ 0 };
	bool is_valid_entry{ false };

	while (!is_valid_entry)
	{
		cout << "Enter a number from 1 to 100. >";
		cin >> number_to_guess;

		if (number_to_guess > 0 && number_to_guess < 101)
		{
			is_valid_entry = true;
		}
		else
		{
			cout << '\n' << "Not a valid entry, please try again." << '\n';
		}

	}


	return 0;
}