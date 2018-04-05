/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 09-1
Rice doubled - full board with int
Overflow error after 31 squares
*/

#include "../../std_lib_facilities.h"

int main()
{
	int square_index = 0;
	int current_amount_of_rice = 1;
	int total_amount_of_rice = current_amount_of_rice;

	cout << "Square" << '\t' << "Amount of rice" << '\t' << "Total rice" << '\n';

	for (square_index = 1; square_index <= 64; ++square_index )
	{
		if (square_index == 1)
		{
			cout << square_index << '\t' << current_amount_of_rice << '\t' << '\t' << total_amount_of_rice << '\n';
		} 
		else
		{
			current_amount_of_rice = current_amount_of_rice * 2;
			total_amount_of_rice = total_amount_of_rice + current_amount_of_rice;
			cout << square_index << '\t' << current_amount_of_rice << '\t' << '\t' << total_amount_of_rice << '\n';
		}
	}

	return 0;
}