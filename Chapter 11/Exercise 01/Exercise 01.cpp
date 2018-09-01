// Jared Mathes
// 2018-09-01
// Chapter 11
// Exercise 01

#include "../../std_lib_facilities.h"

int main()
try
{
	cout << "Please enter an input file name: ";
	string iname;
	cin >> iname;

	ifstream ist{ iname };
	if (!ist) error("Can't open file ",iname);
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	vector<string> file_data;
	while (true)
	{
		string new_data;
		if (!(ist>>new_data)) break;
		file_data.push_back(new_data);
	}

	for (string& data : file_data)
	{
		for (char& x : data)
		{
			x = tolower(x);
		}
	}

	cout << "Please enter an output file name: ";
	string oname;
	cin >> oname;
	
	ofstream ost{ oname };
	if (!ost) error("Can't open file ", oname);

	for (auto const& value : file_data)
	{
		ost << value << endl;
	}

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