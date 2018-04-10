// Jared Mathes
// 2018-04-10
// Chapter 5
// Drill
// Step 17
// char cannot hold the value 2000

#include "../../std_lib_facilities.h"
int main()
try {
	int x = 2000; 
	int c = x; 
	if (c == 2000) cout << "Success!\n";
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