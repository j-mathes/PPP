// Jared Mathes
// 2018-08-25
// Chapter 10
// Exercise 08
// Concatenate two text files

#include "../../std_lib_facilities.h"

void read_contents_of_file(vector<string>& contents, string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	if (!ist) error("Can't open input file, ", filename);

	for (string read_string; getline( ist, read_string);)
	{
		contents.push_back(read_string);
	}

	if (ist.eof()) ist.clear();
	if (ist.fail()) error("File not formatted well > ", filename);
}

void write_concatenated_file(const vector<string> first_file, 
	const string& first_file_name, 
	const vector<string> second_file, 
	const string& second_file_name, 
	const string& third_file_name)
{
	ofstream ost{ third_file_name };
	if (!ost)
	{
		error("Can't open the output file, ", third_file_name);
	}
	for (auto const& value : first_file)
	{
		ost << value << endl;
	}
	for (auto const& value : second_file)
	{
		ost << value << endl;
	}
}

int main()
try
{
	vector<string> first_file;
	vector<string> second_file;
	string first_file_name;
	string second_file_name;
	string third_file_name;

	cout << "This program will concatenate the contents of two files into a third file" << endl << endl;
	cout << "Enter the full name of the first file: >";
	cin >> first_file_name;
	read_contents_of_file(first_file, first_file_name);
	cout << endl;


	cout << "Enter the full name of the second file: >";
	cin >> second_file_name;
	read_contents_of_file(second_file, second_file_name);
	cout << endl;

	cout << "What do you want to name the concatenated file? >";
	cin >> third_file_name;

	write_concatenated_file(first_file, first_file_name, second_file, second_file_name, third_file_name);

	cout << endl << "New file " << third_file_name << " created with the contents of "
		<< first_file_name << " and " << second_file_name << "." << endl << endl;
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