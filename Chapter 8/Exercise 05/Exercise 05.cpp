// Jared Mathes
// 2018-07-20
// Chapter 8
// Exercise 05
// Reverse vector functions

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
	for (int i = 2; i < (n); ++i)
	{
		int next_number = v[i - 1] + v[i - 2];
		v.push_back(next_number);
	}

	return;
}

void reverse_vector(vector<int>& v)
{
	for (size_t i = 0; i < (v.size() / 2); ++i)
	{
		swap(v[i], v[v.size() - 1 - i]);
	}
}

vector<int> reverse_vector_newv(const vector<int>& v)
{
	vector<int> newv;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		newv.push_back(v[i]);
	}
	return newv;
}

int main()
{
	vector<int> my_vector_1;
	vector<int> my_vector_2;

	fibonacci(1, 2, my_vector_1, 5);
	fibonacci(3, 4, my_vector_2, 8);

	reverse_vector(my_vector_1);
	vector<int> my_vector_3 = reverse_vector_newv(my_vector_2);

	print("my_vector_1", my_vector_1);
	print("my_vector_2", my_vector_2);
	print("my_vector_3", my_vector_3);

	return 0;
}