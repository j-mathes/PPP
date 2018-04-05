/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 08
Rice doubled
*/

#include "../../std_lib_facilities.h"

int main()
{
	int square_index = 1;
	int current_amount_of_rice = 1;
	int total_amount_of_rice = current_amount_of_rice;

	cout << "Square" << '\t' << "Amount of rice" << '\t' << "Total rice" << '\n';
	cout << square_index << '\t' << current_amount_of_rice << '\t' << '\t' << total_amount_of_rice << '\n';

	while (total_amount_of_rice < 1000000000)
	{
		++square_index;
		current_amount_of_rice = current_amount_of_rice * 2;
		total_amount_of_rice = total_amount_of_rice + current_amount_of_rice;
		cout << square_index << '\t' << current_amount_of_rice << '\t' << '\t' << total_amount_of_rice << '\n';
	}

	return 0;
}