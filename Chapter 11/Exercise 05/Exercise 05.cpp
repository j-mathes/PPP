//----------------------------------------------------------------------------
// File:	Exercise 05.cpp
// Date:	2018-09-03
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 05
//----------------------------------------------------------------------------
// Description: output the character classification of chars in a a string
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
  cout << "Enter strings.  Output will show the character classification of each string." << endl;
  cout << "Ctrl + c to end." << endl;
  cout << endl << "> ";
  string input;
  
  while (cin >> input)
  {
    cout << endl;

    stringstream ss{ input };

    for (char ch; ss.get(ch);)
    {
      cout << "Character classifications for " << ch << endl;
      cout << "-------------------------------" << endl;
      if (isspace(ch)) cout << " - Whitespace." << endl;
      if (isalpha(ch)) cout << " - Letter." << endl;
      if (isdigit(ch)) cout << " - Digit." << endl;
      if (isxdigit(ch)) cout << " - Hexadecimal digit." << endl;
      if (isupper(ch)) cout << " - Upper case letter." << endl;
      if (islower(ch)) cout << " - Lower case letter." << endl;
      if (isalnum(ch)) cout << " - Alpha / numeric." << endl;
      if (iscntrl(ch)) cout << " - Control character." << endl;
      if (ispunct(ch)) cout << " - Punctuation." << endl;
      if (isprint(ch)) cout << " - Printable." << endl;
      if (isgraph(ch)) cout << " - Alpha / numeric / punctuation." << endl;
      cout << endl;
    }

    cout << endl << "> ";
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