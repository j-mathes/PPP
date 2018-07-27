// Jared Mathes
// 2018-07-26
// Chapter 8
// Exercise 10
// Function maxv()

#include "../../std_lib_facilities.h"

double maxv(vector<double>& v)
{
	if (v.size() == 0)
	{
		error("No elements in the vector.");
	}
	double result = v[0];
	if (v.size() == 1)
	{
		return result;
	}
	else
	{
		for (int i{ 0 }; i < v.size() - 1; ++i)
		{
			if (v[i+1] > result)
			{
				result = v[i + 1];
			}
		}
		return result;
	}
}

int main()
try
{
	vector<double> my_vector{ 1.5, 4.3, 2.6, 19.1, 12.0 };
	
	double max_double = maxv(my_vector);
	cout << max_double << endl;
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