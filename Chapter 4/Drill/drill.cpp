/*
Jared Mathes
2018-03-26
Chapter 4-4
Drill
*/
#include "../../std_lib_facilities.h"

int main()
{
	double number1{ 0.0 };
	double number2{ 0.0 };
	
	cout << "Please enter two numbers separated by a space. >";
	while (cin >> number1 >> number2)
	{
		if (number1 == number2)
		{
			cout << "\nThe numbers are equal!\n";
		} 
		else
		{
			double smaller = number1 < number2 ? number1 : number2;
			cout << "\nThe smaller value is: " << smaller << "\n";

			double larger = number1 > number2 ? number1 : number2;
			cout << "\nThe larger value is: " << larger << "\n";
		}

		cout << "\nPlease enter two numbers separated by a space. >";
	}
	
	return 0;
}