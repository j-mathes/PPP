/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 10
Rock / Paper / Scissors
*/

#include "../../std_lib_facilities.h"

int get_computer_move(int first, int last)
{
	// implementation taken from http://www.cplusplus.com/faq/beginners/random-numbers/

	unsigned int N = (last - first <= RAND_MAX) /* Make sure the algorithm    */
		? (last - first + 1U)					/* terminates by keeping N    */
		: (RAND_MAX + 1U);						/* in rand()'s maximum range. */
	unsigned int x = (RAND_MAX + 1U) / N;
	unsigned int y = x * N;
	unsigned int r;
	do 
	{
		r = rand();
	} while (r >= y);
	
	return r / x + first;
}

bool player_move_valid(char player_move)
{
	if (player_move == 'r' || player_move == 'p' || player_move == 's')
		return true;
	else
		return false;
}

int main()
{
	int computer_move{ 0 };
	char player_move;
	int computer_score{ 0 };
	int player_score{ 0 };

	cout << "Rock, Paper, Scissors.  Enter r, p, or s to make a move.\n";

	while (true)
	{
		computer_move = get_computer_move(1, 3);	// 1=rock, 2=paper, 3=scissors
		cout << "\nComputer has chosen a move.  Now, enter your move (r / p / s).\n";
		cout << "\n> ";
		cin >> player_move;

		if (player_move_valid(player_move))
		{
			char computer_move_char;
			
			switch (computer_move)
			{
			case 1:
				computer_move_char = 'r';
				break;
			case 2:
				computer_move_char = 'p';
				break;
			case 3:
				computer_move_char = 's';
				break;
			}

			cout << "\nComputer's move: " << computer_move_char << ". Your move: " << player_move << ".\n";
			switch (player_move)
			{
			case 'r':
				switch (computer_move)
				{
				case 1:
					cout << "\nTie game.\n";
					break;
				case 2:
					cout << "\nComputer wins!\n";
					++computer_score;
					break;
				case 3:
					cout << "\nPlayer wins!\n";
					++player_score;
					break;
				}
				break;
			case 'p':
				switch (computer_move)
				{
				case 2:
					cout << "\nTie game.\n";
					break;
				case 3:
					cout << "\nComputer wins!\n";
					++computer_score;
					break;
				case 1:
					cout << "\nPlayer wins!\n";
					++player_score;
					break;
				}
				break;
			case 's':
				switch (computer_move)
				{
				case 3:
					cout << "\nTie game.\n";
					break;
				case 1:
					cout << "\nComputer wins!\n";
					++computer_score;
					break;
				case 2:
					cout << "\nPlayer wins!\n";
					++player_score;
					break;
				}
				break;
			}
			cout << "\nComputer's score: " << computer_score << ". Player's score: " << player_score << ".\n";
		} 
		else
		{
			cout << "\nNot a valid move!\n";
		}
	}
	return 0;
}