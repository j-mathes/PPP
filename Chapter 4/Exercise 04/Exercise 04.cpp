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
	int low_range{ 1 };
	int high_range{ 100 };
	int number_to_guess{ 0 };
	bool is_valid_entry{ false };

	while (!is_valid_entry)
	{
		cout << "Enter a number from " << low_range << " to " << high_range << ". > ";
		cin >> number_to_guess;

		if (number_to_guess > (low_range - 1) && number_to_guess < (high_range + 1))
		{
			is_valid_entry = true;
			cout << '\n';
		}
		else
		{
			cout << '\n' << "Not a valid entry, please try again." << '\n';
		}
	}

	int counter{ 1 };
	bool correct{ false };
	char answer;

	while (!correct)
	{
		int median = (low_range + high_range) / 2;
		cout << "For each attempt, answer if the guess is (c)orrect, (l)ower, or (h)igher.\n";
		cout << "Guess number " << counter << ". Is your number " << median << "? > ";
		cin >> answer;
		
		switch (answer)
		{
		case 'c':
		case 'C':
			if (number_to_guess == median)
			{
				cout << "\nGuessed the number " << number_to_guess << " in " << counter << " guess" << ((counter == 1) ? "" : "es") << "!\n";
				correct = true;
			} 
			else
			{
				cout << "Liar!\n\n";
			}
			break;

		case 'l':
		case 'L':
			if (number_to_guess < median)
			{
				high_range = median;
				cout << "\n\n";
				++counter;
			} 
			else
			{
				cout << "Liar!\n\n";
			}
			break;

		case 'h':
		case 'H':
			if (number_to_guess > median)
			{			
				low_range = median;
				cout << "\n\n";
				++counter;
			} 
			else
			{
				cout << "Liar!\n\n";
			}
			break;

		default:
			cout << "\nThat's not a valid entry.  Try again.\n\n";
			--counter;
			break;
		}
	}

	return 0;
}