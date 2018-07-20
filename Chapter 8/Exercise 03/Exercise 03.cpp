// Jared Mathes
// 2018-07-19
// Chapter 8
// Exercise 03
// Print Fibonacci numbers

#include "../../std_lib_facilities.h"

void print(string label, vector<int>& ints)
{
	cout << label << endl;
	for (int x : ints)
	{
		cout << x << endl;
	}
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
	if (n < 2) error("The number of elements needs to be equal to or greater than 2.");
	v.push_back(x);
	v.push_back(y);
	for (int i=2; i < (n); ++i)
	{
		int next_number = v[i - 1] + v[i - 2];
		v.push_back(next_number);
	}

	return;
}

int main()
{
	string int_label = "Sequence:";
	vector<int> my_vector;

	fibonacci(1, 2, my_vector, 5);

	print(int_label, my_vector);
	return 0;
}