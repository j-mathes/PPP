//----------------------------------------------------------------------------
// File:	Exercise 08.cpp
// Date:	2018-09-04
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 08
//----------------------------------------------------------------------------
// Description: Replace punctuation with whitespace.  Ignore between "".
// Expands contractions can't and don't.  Leaves hyphens between words.
// Make a dictionary and run on multi-page text file.
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
  cout << "Please enter an input file name: ";
  string iname;
  cin >> iname;

  ifstream ifs{ iname };
  if (!ifs) error("Can't open file ", iname);
  ifs.exceptions(ifs.exceptions() | ios_base::badbit);

  string s;
  stringstream ss;
  vector<string> temp, dictionary;

  while (ifs)
  {
    getline(ifs, s);
    ss << change_to_whitespace(s);
  }

  for (string word; ss >> word;)
    temp.push_back(word);
  
  sort(temp.begin(), temp.end());

  for (int i=0; i < temp.size(); ++i)
    if (i == 0 || temp[i] != temp[i - 1])
      dictionary.push_back(temp[i]);

  for (string& outp : dictionary)
    cout << outp << endl;

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