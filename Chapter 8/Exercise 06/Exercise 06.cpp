// Jared Mathes
// 2018-07-20
// Chapter 8
// Exercise 06
// Reverse string functions added

#include "../../std_lib_facilities.h"

void print(string label, vector<int>& ints)
{
	cout << label << endl;
	for (int x : ints)
	{
		cout << x << endl;
	}
}

void print(string label, vector<string>& strings)
{
	cout << label << endl;
	for (string x : strings)
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

void reverse_vector_string(vector<string>& v)
{
	for (size_t i = 0; i < (v.size() / 2); ++i)
	{
		swap(v[i], v[v.size() - 1 - i]);
	}
}

vector<string> reverse_vector_string_newv(const vector<string>& v)
{
	vector<string> newv;
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

	print("my_vector_1", my_vector_1);
	reverse_vector(my_vector_1);
	vector<int> my_vector_3 = reverse_vector_newv(my_vector_2);

	print("my_vector_1", my_vector_1);
	print("my_vector_2", my_vector_2);
	print("my_vector_3", my_vector_3);

	vector<string> my_string_vector_1{ "abc", "sdg", "regds", "ggsed", "jsadse" };
	vector<string> my_string_vector_2{ "xfdgh", "rtyjr", "ssdyhfgd", "dfr", "drhdxfh", "ddffrdr" };

	print("my_string_vector_1", my_string_vector_1);
	reverse_vector_string(my_string_vector_1);
	vector<string> my_string_vector_3 = reverse_vector_string_newv(my_string_vector_2);
	print("my_string_vector_1", my_string_vector_1);
	print("my_string_vector_2", my_string_vector_2);
	print("my_string_vector_3", my_string_vector_3);

	return 0;
}