// Jared Mathes
// 2018-07-31
// Chapter 9
// Drill 01
// Date Function
// 9.4.1 version

#include "../../std_lib_facilities.h"

// simple Date
struct Date {
	int y;		// year
	int m;		// month in year
	int d;		// day of month
};

// helper functions:
void init_day(Date& dd, int y, int m, int d)
{
	// check that (y,m,d) is a valid date
	if (y < 1600 || y > 2050 || m < 0 || m > 13 || d < 0 || d > 31)
	{
		error("Invalid date");
	}
	else
	{
		dd.y = y;
		dd.m = m;
		dd.d = d;
	}
	
	// if it is, use it to initialize dd
	return;
}

void add_day(Date& dd, int n)
{
	// increase dd by n days
	int temp_days = dd.d;
	int temp_months = dd.m;

	temp_days += n;
	if (temp_days > 31)
	{
		dd.d = temp_days - 31;
		temp_months++;
	}
	else
	{
		dd.d++;
	}

	if (temp_months > 12)
	{
		dd.m = temp_months - 12;
		dd.y++;
	}

	// This should really call a recursion function in case the number of days exceeds a month's worth.
	// Simple for now.
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}

istream& operator>>(istream& is, Date& dd)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	Date new_date;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is) return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {	// oops: format error
		is.clear(ios_base::failbit);                            // set the fail bit
		return is;
	}

	init_day(new_date, y, m, d);										// update dd                            
	dd = new_date;

	return is;
}

int main()
try
{
	Date today;
	init_day(today, 1978, 6, -25 );

	Date tomorrow = today;
	add_day(tomorrow, 1);

	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}