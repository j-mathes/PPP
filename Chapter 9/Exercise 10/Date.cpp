// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 10
// Library project
// Date.cpp

#pragma once
#include "Date.h"

Date::Date(int yy, Month mm, int dd)
{
	// check that (y,m,d) is a valid date
	if (yy < 1800 || yy > 2200 || mm < Month::jan || mm > Month::dec || dd < 0 || dd > 31)
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

bool Date::leap_year(int y)
{
	bool is_leap_year = false;
	if (y % 4 == 0)
		if (y % 100 == 0)
			if (y % 400 == 0)
				is_leap_year = true;
	return is_leap_year;
}

static ostream& operator<<(ostream& os, const Month& m) {
	switch (m) {
	case Month::jan: os << "January"; break;
	case Month::feb: os << "February"; break;
	case Month::mar: os << "March"; break;
	case Month::apr: os << "April"; break;
	case Month::may: os << "May"; break;
	case Month::jun: os << "June"; break;
	case Month::jul: os << "July"; break;
	case Month::aug: os << "August"; break;
	case Month::sep: os << "September"; break;
	case Month::oct: os << "October"; break;
	case Month::nov: os << "November"; break;
	case Month::dec: os << "December"; break;
	}
	return os;
}

ostream& operator<<(ostream& os, Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}