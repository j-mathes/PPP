/*
Jared Mathes
2018-03-26
Chapter 4-6
Drill
*/
#include "../../std_lib_facilities.h"

int main()
{
	double number{ 0.0 };
	double largest;
	double smallest;
	bool firstTime = true;
	
	cout << "Please enter a number >";
	while (cin >> number)
	{
		if (firstTime)
		{
			smallest = number;
			largest = number;
			cout << smallest << " is the smallest number so far.\n";
			cout << largest << " is the largest number so far.\n";
			firstTime = false;
		}
		cout << "\nThe number entered is " << number << ".\n";
		if (number < smallest)
		{
			smallest = number;
			cout << smallest << " is the smallest number so far.\n";
		} 

		if (number > largest)
		{
			largest = number;
			cout << largest << " is the largest number so far.\n";
		}
		
		cout << "\nPlease enter a number >";
	}
	
	return 0;
}