// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 8
// bool should be changed to true

#include "../../std_lib_facilities.h"
int main()
try {
	bool c = true; 
	if (c) cout << "Success!\n"; 
	else cout << "Fail!\n";
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