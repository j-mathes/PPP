/*
Jared Mathes
2018-03-26
Chapter 4 -1
Drill
*/
#include "../../std_lib_facilities.h"

int main()
{
	int number1{ 0 };
	int number2{ 0 };
	
	cout << "Please enter two integers separated by a space. >";
	while (cin >> number1 >> number2)
	{
		cout << number1 << " " << number2;
		cout << "\n\nPlease enter two integers separated by a space. >";
	}
	
	return 0;
}