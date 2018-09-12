//----------------------------------------------------------------------------
// File:	Exercise 11.cpp
// Date:	2018-09-11
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 11
//----------------------------------------------------------------------------
// Description: Function to return whitespace separated string using custom 
// whitespace identifier
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// Include custom substring identifiers to split.
// Iterate through string.  Substitute ' ' for characters in w.
//----------------------------------------------------------------------------
vector<string> split(const string& s, const string& w)
{
  string a = s;
  for (char& ch : a)
  {
    for (char c : w)
    {
      if (ch == c) ch = ' ';
    }
  }

  istringstream is{ a };
  string newstring;
  vector<string> newstringvector;

  while (is >> newstring) newstringvector.push_back(newstring);

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
  string whitespace{ "ir" };

  vector<string> mystringvector = split(mystring, whitespace);
  for (auto& var : mystringvector)
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