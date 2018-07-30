// Jared Mathes
// 2018-07-29
// Chapter 8
// Exercise 13
// Number of characters in each string in a vector

#include "../../std_lib_facilities.h"

int number_of_chars_in_each(vector<string> v)
{
	int total = 0;
	for (string s : v)
	{
		total += s.size();
	}
	return total;
}

string shortest_string(vector<string> v)
{
	string result = v[0];
	for (string s : v)
	{
		if (s.size() < result.size())
			result = s;
	}

	return result;
}

string longest_string(vector<string> v)
{
	string result = v[0];
	for (string s : v)
	{
		if (s.size() > result.size())
			result = s;
	}

	return result;
}

string lex_first_string(vector<string> v)
{
	string result = v[0];
	for (string s : v)
	{
		if (s < result)
			result = s;
	}

	return result;
}

string lex_last_string(vector<string> v)
{
	string result;
	for (string s : v)
	{
		if (s > result)
			result = s;
	}

	return result;
}

int main()
try
{
	vector<string> my_strings = { "apple", "ball", "chocolate", "door", "elephant" };

	cout << "The number of characters in all strings in the vector: " << number_of_chars_in_each(my_strings) << endl;
	cout << "The shortest string in the vector: " << shortest_string(my_strings) << endl;
	cout << "The longest string in the vector: " << longest_string(my_strings) << endl;
	cout << "The lexicographically first string in the vector: " << lex_first_string(my_strings) << endl;
	cout << "The lexicographically last string in the vector: " << lex_last_string(my_strings) << endl;

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