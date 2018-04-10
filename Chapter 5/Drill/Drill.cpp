// Jared Mathes
// 2018-04-10
// Chapter 5
// Drill
// Step 12
// expression is not a bool type

#include "../../std_lib_facilities.h"
int main()
try {
	string s = "ape"; 
	if (s != "fool")
		cout << "Success!\n";
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}