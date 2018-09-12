//----------------------------------------------------------------------------
// File:	Exercise 13.cpp
// Date:	2018-09-11
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 13
//----------------------------------------------------------------------------
// Description: Reverse order of words in a file.
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

  vector<string> file_strings;
  string s;

  while (ifs >> s) file_strings.push_back(s);

  for (int Index = file_strings.size() - 1; Index >= 0 ; Index--)
  {
    ofs << file_strings[Index];
    ofs << ' ';
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