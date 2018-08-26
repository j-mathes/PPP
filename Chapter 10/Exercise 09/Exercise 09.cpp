// Jared Mathes
// 2018-08-26
// Chapter 10
// Exercise 09
// Read two text files and merge

#include "../../std_lib_facilities.h"

void read_file(vector<string>& contents, string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	if (!ist) error("Can't open input file, ", filename);

	for (string read_string; ist >> read_string;)
	{
		contents.push_back(read_string);
	}

	if (ist.eof()) ist.clear();
	if (ist.fail()) error("File not formatted well > ", filename);
}

void write_file(const vector<string> data, const string& file_name)
{
	ofstream ost{ file_name };
	if (!ost)
	{
		error("Can't open the output file, ", file_name);
	}
	for (auto const& value : data)
	{
		ost << value << endl;
	}
}

int main()
try
{
	vector<string> first_file_data;
	vector<string> second_file_data;
	vector<string> combined_sorted_strings;
	string first_file_name;
	string second_file_name;
	string third_file_name;

	cout << "This program will read the contents of two sorted files into a third file, and maintain the sort." << endl << endl;
	cout << "Enter the full name of the first file: >";
	cin >> first_file_name;
	read_file(first_file_data, first_file_name);
	cout << endl;

	cout << "Enter the full name of the second file: >";
	cin >> second_file_name;
	read_file(second_file_data, second_file_name);
	cout << endl;

	cout << "What do you want to name the third file? >";
	cin >> third_file_name;

	size_t max_data_size = first_file_data.size();
	if (second_file_data.size() > max_data_size)
		max_data_size = second_file_data.size();

	size_t counter{ 0 };
	while (counter < max_data_size)
	{
		if (counter < first_file_data.size())
			combined_sorted_strings.push_back(first_file_data[counter]);
		if (counter < second_file_data.size())
			combined_sorted_strings.push_back(second_file_data[counter]);
		++counter;
	}

	write_file(combined_sorted_strings, third_file_name);

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