// Jared Mathes
// 2018-04-10
// Chapter 5
// Drill
// Step 19
// type of vector not defined

#include "../../std_lib_facilities.h"
int main()
try {
	vector<int> v(5); 
	for (int i = 0; i <= v.size(); ++i); 
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