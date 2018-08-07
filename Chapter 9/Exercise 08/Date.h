// Jared Mathes
// 2018-08-06
// Chapter 9
// Exercise 08
// Library project
// Date.h

#pragma once
#include "../../std_lib_facilities.h"

// enumeration for month
enum class Month 
{
	jan = 1, 
	feb, 
	mar, 
	apr, 
	may, 
	jun, 
	jul, 
	aug, 
	sep, 
	oct, 
	nov, 
	dec
};

class Date {
public:
	Date(int y, Month m, int d);	// check for valid date and initialize

	int day() const { return d; }		// const member: can't modify the object
	Month month() const { return m; }	// const member: can't modify the object
	int year() const { return y; }		// const member: can't modify the object

	void add_day(int n);	// non-const member: can modify the object

private:
	int y;					// year
	Month m;
	int d;					// day of month
};