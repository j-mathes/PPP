//----------------------------------------------------------------------------
// File:	Exercise 12.cpp
// Date:	2018-09-11
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 12
//----------------------------------------------------------------------------
// Description: Reverse contents of a text file.
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

  vector<char> initial_order;
  vector<char> reversed;
  char ch;
  while (ifs)
  {
    ifs.get(ch);
    initial_order.push_back(ch);
  }

  for (int Index = initial_order.size() - 1; Index >= 0 ; Index--)
  {
    reversed.push_back(initial_order[Index]);
    ofs << initial_order[Index];
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