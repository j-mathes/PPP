/*
Jared Mathes
2018-03-21
Chapter 3
Exercise 7 - Sort Three Strings
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will take three strings and sort them.\n";
	cout << "Enter the first string.\n\n";
	cout << "> ";

	string first_string = "";
	cin >> first_string;

	cout << "\nEnter the second string.\n\n";
	cout << "> ";

	string second_string = "";
	cin >> second_string;

	cout << "\nEnter the third string.\n\n";
	cout << "> ";

	string third_string = "";
	cin >> third_string;

	// sort the strings
	string temp = "";

	if (first_string > second_string)
	{
		temp = second_string;
		second_string = first_string;
		first_string = temp;
	}

	if (second_string > third_string)
	{
		temp = third_string;
		third_string = second_string;
		second_string = temp;

		if (first_string > second_string)
		{
			temp = second_string;
			second_string = first_string;
			first_string = temp;
		}
	}

	// display the output

	cout << "\n" << first_string << " , " << second_string << " , " << third_string << "\n\n";

	keep_window_open();
	return 0;
}