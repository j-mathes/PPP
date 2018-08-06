// Jared Mathes
// 2018-08-05
// Chapter 9
// Exercise 06
// Library project
// Book.cpp

#pragma once
#include "Book.h"
#include <regex>

Book::Book(string isbn, string title, string author, Date copyright_date, bool is_checked_out)
	: m_title(title), m_author(author), m_copyright_date(copyright_date), m_is_checked_out(is_checked_out)
{
	if (check_ISBN(isbn))
		m_ISBN = isbn;
	else
		error("ISBN not in correct format");
}

void Book::check_in()
{
	if (is_checked_out())
	{
		m_is_checked_out = false;
	} 
	else
	{
		cout << "This book is already checked in." << endl;
	}
}


void Book::check_out()
{
	if (is_checked_out())
	{
		cout << "This book is already checked out." << endl;
	}
	else
	{
		m_is_checked_out = true;
	}
}

bool Book::check_ISBN(const string& isbn)
{
	regex r("^\\d{9}[\\dX]$");
	return regex_match(isbn, r);
}

ostream& operator<<(ostream& os, Book& b)
{
	return os << "Title: " << b.title() << endl
		<< "Author: " << b.author() << endl
		<< "ISBN: " << b.ISBN() << endl;
}

bool operator!=(const Book& a, const Book& b)
{
	return (a.ISBN() != b.ISBN());
}

bool operator==(const Book& a, const Book& b)
{
	return (a.ISBN() == b.ISBN());
}