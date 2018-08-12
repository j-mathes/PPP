// Jared Mathes
// 2018-08-12
// Chapter 10
// Chapter worksheet
// IO Streams

#include "../../std_lib_facilities.h"

void skip_to_int()
{
	if (cin.fail())
	{												// we found something that wasn't an integer
		cin.clear();								// set the state back to good();
													// we want to look at the characters	
		for (char ch; cin >> ch; )	// throw away non-digits
		{
			if (isdigit(ch) || ch=='-')
			{
				cin.unget();						// put the digit back, so that we can read the number
				return;
			}
		}
	}
	error("no input");								// eof or bad: give up
}

int get_int()
{
	int n = 0;
	while (true)
	{
		if (cin >> n)
			return n;								// if we get what we expect, return, if not, fall through to next statement
		cout << "Sorry, that was not a number; please try again\n";
		skip_to_int();
	}
}

int get_int(int low, int high)
{
	cout << "Please enter an integer in the range " << low << " to " << high << " (inclusive):\n";
	while (true)
	{
		int n = get_int();
		if (low <= n && n <= high) return n;
		cout << "Sorry " << n << " is not in the [" << low << ":" << high << "] range; please try again\n";
	}
}

int main()
try
{
	get_int(1, 10);
	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	keep_window_open("~");
}

catch (...)
{
	cerr << "exception\n";
	keep_window_open("~");
}