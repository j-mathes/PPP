/*
	Jared Mathes
	2018-03-20
	Chapter 3 Drill
	Form Letter Program - Step 3
*/
#include "../../../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;
	cout << "\n";

	cout << "Enter the name of a friend:\n";
	string friend_name;	
	cin >> friend_name;	
	cout << "\n";
	
	cout << "Dear " << first_name << ",\n\n";
	cout << "	How are you doing?  It was so good to hear from you the other day.\n";
	cout << "We are all interested to hear what you have been up to.\n\n";
	cout << "Have you seen " << friend_name << " lately?\n\n";
	cout << "Please respond soon.\n\n";

	keep_window_open();
	return 0;
}