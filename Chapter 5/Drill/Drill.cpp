// Jared Mathes
// 2018-04-10
// Chapter 5
// Drill
// Step 15
// test expression should loop to the max size of 's'

#include "../../std_lib_facilities.h"
int main()
try {
	string s = "Success!\n"; 
	for (int i = 0; i < s.size(); ++i) 
		cout << s[i];
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