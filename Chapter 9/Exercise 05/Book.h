// Jared Mathes
// 2018-08-04
// Chapter 9
// Exercise 05
// Library project
// Book.h

#pragma  once
#include"Date.h"
#include "../../std_lib_facilities.h"

class Book
{
public:
	Book(string isbn, string title, string author, Date copyright_date, bool is_checked_out);
	string ISBN() const { return m_ISBN; }
	string title() const { return m_title; }
	string author() const { return m_author; }
	Date copyright_date() const { return m_copyright_date; }
	bool is_checked_out() const { return m_is_checked_out; }
	void check_in();
	void check_out();
	bool check_ISBN(const string&);

private:
	string m_ISBN;
	string m_title;
	string m_author;
	Date m_copyright_date;
	bool m_is_checked_out;
};