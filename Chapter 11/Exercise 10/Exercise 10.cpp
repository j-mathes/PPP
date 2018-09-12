//----------------------------------------------------------------------------
// File:	Exercise 10.cpp
// Date:	2018-09-11
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 10
//----------------------------------------------------------------------------
// Description: Function to return whitespace separated string
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// Takes a string.  Using traditional whitespace, returns a vector of strings
// separated by that whitespace.
//----------------------------------------------------------------------------
vector<string> split(const string& s)
{
  stringstream ss{ s };
  string newstring;
  vector<string> newstringvector;

  while (ss >> newstring) newstringvector.push_back(newstring);

  return newstringvector;
}

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
  string mystring{ "This is a string separated by whitespace. \n Pretty neat!" };
  cout << mystring << endl;

  vector<string> mystringvector = split(mystring);
  for (auto var: mystringvector)
  {
    cout << var << endl;
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