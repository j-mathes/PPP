// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 3
// statement not terminated with ;
// string not enclosed in "

#include "../../std_lib_facilities.h"
int main()
try {
	cout << "Success" << "!\n";
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