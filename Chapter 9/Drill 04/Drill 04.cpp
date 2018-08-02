// Jared Mathes
// 2018-08-02
// Chapter 9
// Drill 04
// Date Function
// 9.7.1 version

#include "../../std_lib_facilities.h"

// enumeration for month
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// simple Date
class Date {

public:
	Date(int y, Month m, int d);	// check for valid date and initialize
	void add_day(int n);			// increase the Date by n days
	
	int year() const { return y; }
	Month month() const { return m; }
	int day() { return d; }

private:
	int y;		// year
	Month m;	// month in year
	int d;		// day of month
};

// helper functions:
Date::Date(int yy, Month mm, int dd)
{
	// check that (y,m,d) is a valid date
	if ( yy < 1800 || yy > 2200 || mm < Month::jan || mm > Month::dec || dd < 0 || dd > 31)
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
	int temp_months = (int)m;

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
		m = (Month)(temp_months - 12);
		y++;
	}
	else
	{
		m = (Month)temp_months;
	}
}


ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}

istream& operator>>(istream& is, Date& dd)
{
	int y, d;
	Month m;
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
	Date today(1978, Month::jun, 25);

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