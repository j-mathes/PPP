//----------------------------------------------------------------------------
// File:	Exercise 14.cpp
// Date:	2018-09-12
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 14
//----------------------------------------------------------------------------
// Description: Read a file and output the number of characters for each type
// of classification.
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

  int count_space{ 0 };
  int count_alpha{ 0 };
  int count_digit{ 0 };
  int count_xdigit{ 0 };
  int count_upper{ 0 };
  int count_lower{ 0 };
  int count_alnum{ 0 };
  int count_cntrl{ 0 };
  int count_punct{ 0 };
  int count_print{ 0 };
  int count_graph{ 0 };

  char ch;

  while (ifs)
  {
    ifs.get(ch);
      if (isspace(ch)) ++count_space; // These can assert in debug mode if the ascii value is not between 0 and 255.  Just run in release
      if (isalpha(ch)) ++count_alpha;
      if (isdigit(ch)) ++count_digit;
      if (isxdigit(ch)) ++count_xdigit;
      if (isupper(ch)) ++count_upper;
      if (islower(ch)) ++count_lower;
      if (isalnum(ch)) ++count_alnum;
      if (iscntrl(ch)) ++count_cntrl;
      if (ispunct(ch)) ++count_punct;
      if (isprint(ch)) ++count_print;
      if (isgraph(ch)) ++count_graph;
  }

  cout << "Character classification type counts found in the file:" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "Space: " << count_space << endl;
  cout << "Alpha: " << count_alpha << endl;
  cout << "Digit: " << count_digit << endl;
  cout << "Hexadecimal digit: " << count_xdigit << endl;
  cout << "Upper case letter: " << count_upper << endl;
  cout << "Lower case letter: " << count_lower << endl;
  cout << "Alpha / numeric: " << count_alnum << endl;
  cout << "Control: " << count_cntrl << endl;
  cout << "Punctuation: " << count_punct << endl;
  cout << "Printable: " << count_print << endl;
  cout << "Alpha / numeric / punctuation: " << count_graph << endl;

  //keep_window_open();

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