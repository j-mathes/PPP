// Jared Mathes
// 2018-07-29
// Chapter 8
// Exercise 12
// Improve print_until_s()

#include "../../std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
	for (string s : v) {
		if (s == quit) return;
		cout << s << '\n';
	}
	return;
}

void print_until_ss(vector<string> v, string quit)
{
	int counter = 0;
	for (string s : v) {
		if (s == quit) ++counter;
		if (counter >= 2) return;
			cout << s << '\n';
	}
	return;
}

int main()
try
{
	vector<string> my_string = { "apple", "ball", "quarter", "smell", "ball" };

	print_until_s(my_string, "quarter");
	print_until_ss(my_string, "ball");
	print_until_s(my_string, "zero");

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