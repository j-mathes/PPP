// Jared Mathes
// 2018-06-08
// Chapter 6
// Exercise 08
// Bulls and Cows
// using four letters

#include "../../std_lib_facilities.h"

int main()
{
	vector<char> characters_to_guess{ 'a', 'd', 'h', 'r' };
	bool correct = false;

	int bulls{ 0 };
	int cows{ 0 };
	bool bulls_single{ false };
	bool cows_single{ false };

	cout << "Guess 4 characters.\n\n";

	while (!correct)
	{
		vector<char> users_guess;
		for (int i = 0; i < 4; ++i)
		{
			char input;
			cin >> input;

			if (cin.good())
			{
				users_guess.push_back(input);
			}
			else
			{
				cout << "You need to enter a character.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				--i;
			}
		}

		for (unsigned i = 0; i < users_guess.size(); ++i)
		{
			if (users_guess[i] == characters_to_guess[i])
			{
				++bulls;
			}

			for (unsigned j = 0; j < users_guess.size(); ++j)
			{
				if (j != i)
				{
					if (users_guess[j] == characters_to_guess[i])
					{
						++cows;
					}
				}
			}
		}

		if (bulls == 1) bulls_single = true;
		if (cows == 1) cows_single = true;

		cout << '\n' << bulls << ((bulls_single == true) ? " bull and " : " bulls and ") << cows << ((cows_single == true) ? " cow.\n" : " cows.\n");

		if (bulls == 4)
		{
			correct = true;
			cout << "\nYou win!\n\n";
		}
		else
		{
			bulls = 0;
			cows = 0;
			bulls_single = false;
			cows_single = false;
		}

	}

	return 0;
}