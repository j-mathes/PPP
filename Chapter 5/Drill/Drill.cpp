// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 6
// vector indices should be in square brackets
// comparison should be == instead of !=

#include "../../std_lib_facilities.h"
int main()
try {
	vector<int> v(10); 
	v[5] = 7; 
	if (v[5] == 7) cout << "Success!\n";
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