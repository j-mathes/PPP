//----------------------------------------------------------------------------
// File:	multi_input.cpp
// Date:	2018-09-02
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 04
//----------------------------------------------------------------------------
// Description: Accept multi-input types and output as decimal
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

constexpr char prompt = '>';

//----------------------------------------------------------------------------
// Number_base
//----------------------------------------------------------------------------
// Data structure to hold user-entered number and base type
//----------------------------------------------------------------------------
struct Number_base 
{
	int num;
	char base;
};

//----------------------------------------------------------------------------
// output_values
//----------------------------------------------------------------------------
// Function to take a variable of type Number_base and format the output
//----------------------------------------------------------------------------
void output_values(Number_base i)
{
	throw std::logic_error("The method or operation is not implemented.");
}


//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	cout << "Enter integers in decimal, octal, or hexadecimal." << endl;
	cout << "No prefix needed for decimal.  Use '0' for octal and '0x' for hexadecimal." << endl;
	cout << prompt;

	char ch;
	string s;
	vector<Number_base> values;
	while (cin.get(ch))
	{
		Number_base a;

		if (!isdigit(ch))
		{
			if (isalpha(ch)) error("Non integer entered.");
			continue;
		}

		if (ch == '0')
		{
			cin.get(ch);
			if (ch == 'x')
			{
				cin >> std::hex >> a.num;
				a.base = 'h';
			}
			else if (isdigit(ch))
			{
				cin.unget();
				cin >> std::oct >> a.num;
				a.base = 'o';
			}
			else
			{
				cin.unget();
				a.num = 0;
				a.base = 'o';
			}
		}
		else
		{
			cin.unget();
			cin >> a.num;
			a.base = 'd';
		}
		values.push_back(a);
	}

	for (Number_base i : values)
		output_values(i);

	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}