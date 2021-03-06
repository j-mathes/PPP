// Jared Mathes
// 2018-09-01
// Chapter 11
// Exercise 01
// Convert contents of a file to lower case

#include "../../std_lib_facilities.h"

int main()
try
{
	cout << "Please enter an input file name: ";
	string iname;
	cin >> iname;
	
	cout << "Please enter an output file name: ";
	string oname;
	cin >> oname;

	ifstream ifs{ iname };
	if (!ifs) error("Can't open file ",iname);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	ofstream ofs{ oname };
	if (!ofs) error("Can't open file ", oname);

	string s;
	while (ifs)
	{
		getline(ifs, s);
		for (char& ch : s) ch = tolower(ch);
		ofs << s << endl;
		s.clear();
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