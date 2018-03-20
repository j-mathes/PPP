/*
	Jared Mathes
	2018-03-20
	Chapter 3 Drill
	Form Letter Program - Step 5
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

	cout << "If your friend is male, enter the letter M.\n";
	cout << "If your friend is female, enter the letter F.\n";
	char friend_sex = 0;
	cin >> friend_sex;
	cout << "\n";

	cout << "How old is the recipient of the letter?\n";
	int age = 0;
	cin >> age;
	if (age <= 0 || age >= 110)
	{
		simple_error("You're Kidding!\n");
	}
	cout << "\n";
	
	cout << "\n\n";
	cout << "Dear " << first_name << ",\n\n";
	cout << "	How are you doing?  It was so good to hear from you the other day.\n";
	cout << "We are all interested to hear what you have been up to.\n\n";
	cout << "I hear you just had a birthday and you are " << age << " years old!\n";
	cout << "Have you seen " << friend_name << " lately?\n\n";

	if (friend_sex == 'm' || friend_sex == 'M')
	{
		cout << "If you see " << friend_name << ", please ask him to call me.\n";
	}

	if (friend_sex == 'f' || friend_sex == 'F')
	{
		cout << "If you see " << friend_name << ", please ask her to call me.\n";
	}

	cout << "Please respond soon.\n\n";

	keep_window_open();
	return 0;
}