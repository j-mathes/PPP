// Jared Mathes
// 2018-04-09
// Chapter 5
// Drill
// Step 5
// 'res' should be defined as int

#include "../../std_lib_facilities.h"
int main()
try {
	int res = 7; 
	vector<int> v(10); 
	v[5] = res; 
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