// Jared Mathes
// 2018-05-03
// Chapter 5
// Exercise 13
// Bulls and Cows
// Randomly generated number to guess

#include "../../std_lib_facilities.h"
#include <time.h>

int main()
{
	cout << "------------------\n";
	cout << "- Bulls and Cows -\n";
	cout << "------------------\n";

	bool keep_playing {true};

	while (keep_playing)
	{
		srand(time(NULL));
		vector<int> numbers_to_guess;
		for (int i = 0; i < 4; ++i)
		{
			numbers_to_guess.push_back(randint(9));
		}
		bool correct = false;

		int bulls{ 0 };
		int cows{ 0 };
		bool bulls_single{ false };
		bool cows_single{ false };

		cout << "Guess 4 digits.\n\n";

		while (!correct)
		{
			vector<int> users_guess;
			for (int i = 0; i < 4; ++i)
			{
				int value;
				cin >> value;

				if (cin.good())
				{
					users_guess.push_back(value);
				}
				else
				{
					cout << "You need to enter an integer digit.\n";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					--i;
				}
			}

			for (unsigned i = 0; i < users_guess.size(); ++i)
			{
				if (users_guess[i] == numbers_to_guess[i])
				{
					++bulls;
				}

				for (unsigned j = 0; j < users_guess.size(); ++j)
				{
					if (j != i)
					{
						if (users_guess[j] == numbers_to_guess[i])
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
				
				while (true)
				{
					cout << "Keep playing? (Y)es or (N)o > ";
					string response;
					cin >> response;
					if (response == "Y" || response == "y" || response == "Yes" || response == "yes")
					{
						keep_playing = true;
						bulls = 0;
						cows = 0;
						bulls_single = false;
						cows_single = false;
						break;
					}
					else if (response == "N" || response == "n" || response == "No" || response == "no")
					{
						keep_playing = false;
						break;
					}
				}
			}
			else
			{
				bulls = 0;
				cows = 0;
				bulls_single = false;
				cows_single = false;
			}

		}
	}

	return 0;
}