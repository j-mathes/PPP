// Jared Mathes
// 2018-07-23
// Chapter 8
// Exercise 07
// Name / age pairs

#include "../../std_lib_facilities.h"

void print_names(const vector<string>& strings, const vector<int>& ints)
{
	for (int i = 0; i < strings.size(); ++i)
	{
		cout << strings[i] << ", " << ints[i] << "." << endl;
	}
	return;
}

int find_index(const vector<string> string_vector, const string& s)
{
	for (int i = 0; i < string_vector.size(); ++i)
	{
		if (string_vector[i] == s)
			return i;
	}
	error("That name is not found.");
}

void sort_names(const vector<string>& strings, const vector<int>& ints)
{
	vector<string> strings_copy = strings;
	vector<int> ints_copy;

	sort(strings_copy.begin(), strings_copy.end());
	for (int i = 0; i < strings_copy.size(); ++i)
	{
		ints_copy.push_back(ints[find_index(strings, strings_copy[i])]);
	}
	print_names(strings_copy, ints_copy);
}

int main()
try
{
	vector<string> name;
	vector<int> age;
	int counter{ 1 };

	cout << "Enter a list of names.  Finish by typing 'EOF'." << endl << endl;
	
	while(true)
	{
		cout << "Enter name #" << counter << ". > ";
		string inp;
		cin >> inp;
		if (!cin) error("Unexpected end of file or error on stdin.");
		if (inp == "EOF")
		{
			cout << endl << endl;
			break;
		}
		name.push_back(inp);
		cout << endl;
		++counter;
	}

	for (string string_name: name)
	{
		cout << "Enter the age of " << string_name << ". > ";
		int inp;
		cin >> inp;
		age.push_back(inp);
		cout << endl;
	}

	print_names(name, age);
	cout << endl << endl;
	sort_names(name, age);

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