/*
Jared Mathes
2018-04-02
Chapter 4
Exercise 01 - Try This 4.5.1
square
*/
#include "../../std_lib_facilities.h"

int square(int x)
{
	int variable_result{ 0 };
	for (int i{ 0 }; i < x; i++)
	{
		variable_result = variable_result + x;
	}
	return variable_result;
}

int main()
{
	cout << square(2) << '\n';
	cout << square(100) << '\n';

	return 0;
}