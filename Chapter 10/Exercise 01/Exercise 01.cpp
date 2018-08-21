// Jared Mathes
// 2018-08-20
// Chapter 10
// Exercise 01
// Sum of all numbers in a file of whitespace-separated integers.
// Still need to test

#include "../../std_lib_facilities.h"

// I think this will read whitespace properly and move to the next integer.
// If not, overload the >> operator to do it?
void read_integers(vector<int>& vector_of_ints, const string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	for (int var; ist>>var;)
	{
		vector_of_ints.push_back(var);
	}
	if (ist.eof()) return;
	if (ist.bad()) error("Bad input stream");
}

int main()
try
{
	vector<int> list_of_ints;
	string filename{ "data.txt" };
	read_integers(list_of_ints, filename);
	int sum{ 0 };

	for (auto const& value : list_of_ints)
	{
		sum += value;
	}

	cout << sum;

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