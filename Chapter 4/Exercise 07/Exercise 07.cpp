/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 07
Simple Calculator that accepts single digits or text numbers that represent single digits
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

int get_number()
{
	const int not_a_symbol = literal_number.size();	
	int val = not_a_symbol;
	if (cin >> val) return val;	

	cin.clear();
	string s;
	cin >> s;
	for (int i = 0; i < literal_number.size(); ++i)	
		if (literal_number[i] == s) val = i;
	if (val == not_a_symbol) error("unexpected number string: ", s);

	return val;
}

int main()
{
	initialize_numbers();

	cout << "*****************\n";
	cout << "Simple calculator\n";
	cout << "*****************\n";
	cout << "\n";
	cout << "Enter two single number digits (or their text representation) and one of the four operators: +, -, *, /" << '\n';

	while (true)
	{
		cout << "> ";

		int first_number = get_number();
		int second_number = get_number();
		char op = 0;
		cin >> op;

		switch (op)
		{
		case '+':
			cout << "\n" << first_number << " + " << second_number << " = " << first_number + second_number << "\n";
			break;
		case '-':
			cout << "\n" << first_number << " - " << second_number << " = " << first_number - second_number << "\n";
			break;
		case '*':
			cout << "\n" << first_number << " * " << second_number << " = " << first_number * second_number << "\n";
			break;
		case '/':
			cout << "\n" << first_number << " / " << second_number << " = " << first_number / second_number << "\n";
			break;
		default:
			cout << "\n" << op << " isn't a valid operator.\n";
			break;
		}
	}
	return 0;
}