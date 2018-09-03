//----------------------------------------------------------------------------
// File:	Exercise 06.cpp
// Date:	2018-09-03
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 06
//----------------------------------------------------------------------------
// Description: Replace punctuation with whitespace.  Ignore between "".
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
  cout << "Enter some text to have whitespace removed.  Anything within double" << endl;
  cout << "quotes will be left alone. Ctrl + Z to enter, Ctrl + C to exit." << endl << endl;

  char ch;
  string s;
  //ostringstream oss;
  while (cin.get(ch))
  {
    if (ch == '"')
    {
      s += ch;
      while (cin.get(ch))
      {
        if (ch != '"')
        {
          s += ch;
        }
        else
        {
          s += ch;
          break;
        }
      }
    }
    else
    {
      switch (ch)
      {
      case '.':
      case ';':
      case ',':
      case '?':
      case '-':
      case '\'':
      {
        s += ' ';
        break;
      }

      default:
      {
        s += ch;
        break;
      }
      }
    }
  }
  cout << s << endl;
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