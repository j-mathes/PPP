// Jared Mathes
// 2018-07-19
// Chapter 8
// Exercise 02
// Print function

#include "../../std_lib_facilities.h"

void print(string label, vector<int>& ints)
{
	cout << label << endl;
	for (size_t x:ints)
	{
		cout << x << endl;
	}
}

int main()
{
	string int_label = "Integers:";
	vector<int> my_vector{
		1,
		3,
		4,
		7,
		9,
		12,
		45,
		67,
	};

	print(int_label, my_vector);
	return 0;
}