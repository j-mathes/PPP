//----------------------------------------------------------------------------
// File:	Exercise 06.cpp
// Date:	2018-09-03
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 07
//----------------------------------------------------------------------------
// Description: Replace punctuation with whitespace.  Ignore between "".
// Expands contractions can't and don't.  Leaves hyphens between words.
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// Function to change certain characters to whitespace and return new string
//----------------------------------------------------------------------------
string change_to_whitespace(string s)
{
  string r, p;
  bool quote = false;
  for (char& ch : s)
  {
    if (ch == '"') quote = quote ? false : true;
    if (!quote)
    {
      switch (ch)
      {
      case '.':
      case ';':
      case ',':
      case '?':
      case '-':
      case '\'':
        ch = ' ';
      }
    }
    r += ch;
  }

  istringstream is{ r };
  string o;
  
  while (is >> o)
  {
    for (char& ch : o) ch = tolower(ch);

    if (o == "don't") o = "do not";
    else if (o == "can't") o = "cannot";

    p += o + " ";
  }
  return p;
}

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
  cout << "Enter some text to have whitespace removed.  Anything within double" << endl;
  cout << "quotes will be left alone. Ctrl + Z to enter, Ctrl + C to exit." << endl << endl;

  string s;
  ostringstream oss;
  
  while (getline(cin, s))
  {
    oss << change_to_whitespace(s);
  }
  
  cout << oss.str() << endl;
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