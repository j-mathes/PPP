// Jared Mathes
// 2018-08-02
// Chapter 9
// Drill 03
// Date Function
// 9.4.3 version

#include "../../std_lib_facilities.h"

// simple Date
class Date {
	int y;		// year
	int m;		// month in year
	int d;		// day of month

public:
	Date(int y, int m, int d);	// check for valid date and initialize
	void add_day(int n);		// increase the Date by n days
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};

// helper functions:
Date::Date(int yy, int mm, int dd)
{
	// check that (y,m,d) is a valid date
	if (yy < 1600 || yy > 2050 || mm < 0 || mm > 13 || dd < 0 || dd > 31)
	{
		error("Invalid date");
	}
	else
	{
		y = yy;
		m = mm;
		d = dd;
	}
}

void Date::add_day(int n)
{
	// increase dd by n days
	int temp_days = d;
	int temp_months = m;

	temp_days += n;
	if (temp_days > 31)
	{
		d = temp_days - 31;
		temp_months++;
	}
	else
	{
		d++;
	}

	if (temp_months > 12)
	{
		m = temp_months - 12;
		y++;
	}

	// This should really call a recursion function in case the number of days exceeds a month's worth.
	// Simple for now.
}

ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}

istream& operator>>(istream& is, Date& dd)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4;

	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is) return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {	// oops: format error
		is.clear(ios_base::failbit);                            // set the fail bit
		return is;
	}

	Date new_date(y, m, d);
	dd = new_date;

	return is;
}

int main()
try
{
	Date today(1978, 6, 25);

	Date tomorrow = today;
	tomorrow.add_day(1);

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