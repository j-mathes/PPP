/*
Jared Mathes
2018-03-26
Chapter 4-2
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
		int smaller = number1 < number2 ? number1 : number2;
		cout << "\n\nThe smaller value is :" << smaller;

		int larger = number1 > number2 ? number1 : number2;
		cout << "\nThe larger value is :" << larger;
		cout << "\n\nPlease enter two integers separated by a space. >";
	}
	
	return 0;
}