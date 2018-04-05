/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 06
Convert digits to words - No error checking.  Will crash on wrong input.
*/
#include "../../std_lib_facilities.h"

vector<string> literal_number;

void initialize_numbers()
{
	literal_number.push_back("zero");
	literal_number.push_back("one");
	literal_number.push_back("two");
	literal_number.push_back("three");
	literal_number.push_back("four");
	literal_number.push_back("five");
	literal_number.push_back("six");
	literal_number.push_back("seven");
	literal_number.push_back("eight");
	literal_number.push_back("nine");
}

int main()
{
	initialize_numbers();

	bool is_digit{ true };
	int output_value{ 0 };

	while (true)
	{
		cout << "\nEither enter a digit or enter the word for the digit (i.e. '7' or 'seven').\n";
		cout << "> ";

		const int not_a_symbol = literal_number.size();
		int val = not_a_symbol;
		if (cin >> val)
		{
			is_digit = true;
		}
		else
		{
			cin.clear();
			string s;
			cin >> s;
			for (int i = 0; i < literal_number.size(); ++i)
				if (literal_number[i] == s) val = i;
			if (val == not_a_symbol) error("unexpected number string: ", s);
			is_digit = false;
		}
		output_value = val;

		switch (is_digit)
		{
		case false:
			cout << val << '\n';
			break;
		case true:
			cout << literal_number[val] << '\n';
			break;
		}
	}

	return 0;
}