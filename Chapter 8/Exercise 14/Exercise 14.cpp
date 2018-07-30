// Jared Mathes
// 2018-07-29
// Chapter 8
// Exercise 13
// Const non-reference variable
// We may want to do this to prevent us from accidentally changing the value

#include "../../std_lib_facilities.h"

int number_of_chars_in_each(const vector<string>& v)
{
	int total = 0;
	for (string s : v)
	{
		total += s.size();
	}
	return total;
}



int main()
try
{
	vector<string> my_strings = { "apple", "ball", "chocolate", "door", "elephant" };

	cout << "The number of characters in all strings in the vector: " << number_of_chars_in_each(my_strings) << endl;

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