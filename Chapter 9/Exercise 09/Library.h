// Jared Mathes
// 2018-08-06
// Chapter 9
// Exercise 09
// Library project
// Library.h

#pragma once
#include "../../std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Date.h"

// Need to build constructor for library class
class Library
{
public:
	struct Transaction
	{
		Book book;
		Patron patron;
		Date date;

		Transaction(Book b, Patron p, Date d);
	};

	void add_book(const Book&);
	void add_patron(const Patron&);
	void check_out_book(Book&, const Patron&, const Date&);
	vector <Patron> patrons_who_owe_fees() const;

private:
	vector <Book> m_book;
	vector <Patron> m_patron;
	vector <Transaction> m_transaction;
};

