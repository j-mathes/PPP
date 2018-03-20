/*
	Jared Mathes
	2018-03-20
	Chapter 3 Drill
	Form Letter Program - Step 2
*/
#include "../../../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;		// first_name is a variable of type string
	cin >> first_name;		// read characters into first_name

	cout << "\n";
	cout << "Dear " << first_name << ",\n\n";

	cout << "	How are you doing?  It was so good to hear from you the other day.\n";
	cout << "We are all interested to hear what you have been up to.\n";
	cout << "Please respond soon.\n\n";

	keep_window_open();
	return 0;
}