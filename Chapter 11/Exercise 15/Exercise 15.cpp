//----------------------------------------------------------------------------
// File:	Exercise 15.cpp
// Date:	2018-09-12
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 15
//----------------------------------------------------------------------------
// Description: Read whitespace separated numbers and output them to a file
// using scientific notation.
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

  ifstream ifs{ iname };
  if (!ifs) error("Can't open file ", iname);
  ifs.exceptions(ifs.exceptions() | ios_base::badbit);

  cout << "Please enter an output file name: ";
  string oname;
  cin >> oname;

  ofstream ofs{ oname };
  if (!ofs) error("Can't open file ", oname);

  double d1, d2, d3, d4;

  ofs.setf(ios_base::left, ios_base::adjustfield);

  while (ifs >> d1 >> d2 >> d3 >> d4)
  {
    ofs << scientific << setprecision(8) << setw(20) << d1 << setw(20) << d2 << setw(20) << d3 << setw(20) << d4 << endl;
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