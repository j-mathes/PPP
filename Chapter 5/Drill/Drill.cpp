// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 9
// 'c' not properly defined as bool
// changed comparison to determine 'c'

#include "../../std_lib_facilities.h"
int main()
try {
	string s = "ape"; 
	bool c = "fool" > s; 
	if (c) cout << "Success!\n";
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