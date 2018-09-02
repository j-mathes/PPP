//----------------------------------------------------------------------------
// File:	Exercise 03.cpp
// Date:	2018-09-02
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 03
//----------------------------------------------------------------------------
// Description: Remove all vowels from a file
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
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
	if (!ifs) error("Can't open file ", iname);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	ofstream ofs{ oname };
	if (!ofs) error("Can't open file ", oname);

	string vowel("aeiouAEIOU");
	ostringstream oss;
	char ch;
	while (ifs)
	{
		ifs.get(ch);
		bool i = false;
		for (char x : vowel)
		{
			if (ch == x) i = true;
		}
		if (!i) oss << ch;
	}

	ofs << oss.str();

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