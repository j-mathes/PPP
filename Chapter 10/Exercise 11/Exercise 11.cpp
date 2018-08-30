// Jared Mathes
// 2018-08-29
// Chapter 10
// Exercise 11
// Sum whitespace separated integers in a file

#include "../../std_lib_facilities.h"

void read_file(const string& filename, vector<int>& contents)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	if (!ist) error("Can't open input file, ", filename);

	for (string read_string; ist >> read_string;)
	{
		if (isdigit(read_string[0]))
		{
			stringstream string_to_int(read_string);
			int new_int{ 0 };
			string_to_int >> new_int;
			contents.push_back(new_int);
		}
	}

	if (ist.eof()) ist.clear();
	if (ist.fail()) error("File not formatted well > ", filename);
}

int main()
try
{
	vector<int> file_ints;
	string file_name;

	cout << "This program will read the contents a file a sum any whitespace separated integers it finds." << endl << endl;
	cout << "Enter the full name of the file: >";
	cin >> file_name;
	read_file(file_name, file_ints);
	cout << endl;

	int sum{ 0 };
	for (auto const& value : file_ints)
	{
		sum += value;
	}

	cout << "The sum of all the integers in " << file_name << " is: " << sum << "." << endl;

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