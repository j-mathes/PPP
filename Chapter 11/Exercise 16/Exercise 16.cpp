//----------------------------------------------------------------------------
// File:	Exercise 16.cpp
// Date:	2018-09-12
// Author:	Jared Mathes
//----------------------------------------------------------------------------
// Solution:Chapter 11
// Project:	Exercise 16
//----------------------------------------------------------------------------
// Description: Read a file of whitespace-separated numbers and output them in order
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

//----------------------------------------------------------------------------
// digit struct
//----------------------------------------------------------------------------
struct Number_freq
{
  float num;
  int count;
};

//----------------------------------------------------------------------------
// sort vector
//----------------------------------------------------------------------------
void sort(vector<Number_freq>& n)
{
  bool end = false;
  while (!end)
  {
    end = true;
    for (int i = 0; i < n.size() - 1; i++ )
    {
      if (n[i].num > n[i+1].num)
      {
        Number_freq a;
        a = n[i + 1];
        n[i + 1] = n[i];
        n[i] = a;
        end = false;
      }
    }
  }
}

//----------------------------------------------------------------------------
// count duplicates
//----------------------------------------------------------------------------
void count_duplicates(vector<Number_freq>& n)
{
  for (int i = 0; i < n.size(); i++)
  {
    for (int x = 0; x < n.size(); x++)
    {
      if (i != x)
      {
        if (n[i].num == n[x].num)
        {
          n[i].count++;
          n[x].num = 0;
        }
      }
    }
  }
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

  vector<Number_freq> numbers;
  Number_freq n{ 0,0 };

  while (ifs >> n.num) numbers.push_back(n);

  sort(numbers);
  count_duplicates(numbers);

  for (Number_freq x : numbers) if (x.num != 0) cout << x.num << '\t' << x.count << endl;

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