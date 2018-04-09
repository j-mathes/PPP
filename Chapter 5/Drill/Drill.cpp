// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 4
// string variable 'success' not defined

#include "../../std_lib_facilities.h"
int main()
try {
	string success = "Success!";
	cout << success << '\n';
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