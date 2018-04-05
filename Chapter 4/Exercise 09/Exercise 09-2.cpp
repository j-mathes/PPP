/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 09-2
Rice doubled - full board with double
Gets to all 64 squares with the last reporting 9.22337e+18 and 1.84467e+19
*/

#include "../../std_lib_facilities.h"

int main()
{
	int square_index = 0;
	double current_amount_of_rice = 1.0;
	double total_amount_of_rice = current_amount_of_rice;

	cout << "Square" << '\t' << "Amount of rice" << '\t' << "Total rice" << '\n';

	for (square_index = 1; square_index <= 64; ++square_index)
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