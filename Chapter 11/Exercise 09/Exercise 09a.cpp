//----------------------------------------------------------------------------
// File:	Exercise 09a.cpp
// Date:	2018-09-04
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 09
//----------------------------------------------------------------------------
// Description: Convert text to binary
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
  // open an istream for binary input from a file:
  cout << "Please enter input file name\n";
  string iname;
  cin >> iname;
  ifstream ifs{ iname,ios_base::binary };             // note: stream mode
            // binary tells the stream not to try anything clever with the bytes
  if (!ifs) error("can't open input file ", iname);

  // open an ostream for binary output to a file:
  cout << "Please enter output file name\n";
  string oname;
  cin >> oname;
  ofstream ofs{ oname,ios_base::binary };        // note: stream mode
            // binary tells the stream not to try anything clever with the bytes
  if (!ofs) error("can't open output file ", oname);

 // vector<int> v;

  // read from binary file:
  for (int x; ifs.read(as_bytes(x), sizeof(int)); )   // note: reading bytes
 //   v.push_back(x);
    ofs << x << endl;
 // write to binary file:
 // for (int x : v)
 //   ofs.write(as_bytes(x), sizeof(int));         // note: writing bytes

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