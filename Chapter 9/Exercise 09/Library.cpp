// Jared Mathes
// 2018-08-06
// Chapter 9
// Exercise 09
// Library project
// Library.cpp

#include "Library.h"

Library::Transaction::Transaction(Book b, Patron p, Date d)
	:

void Library::add_book(Book book_to_add)
{
	m_book.push_back(book_to_add);
}

void Library::add_patron(Patron patron_to_add)
{
	m_patron.push_back(patron_to_add);
}

void Library::check_out_book(Book book_requested, Patron patron)
{
	if (find(m_book.begin(), m_book.end(), book_requested) == m_book.end())
	{
		error(book_requested.title(), " is not a book this library carries.");
		return;
	}

	if (find(m_patron.begin(), m_patron.end(), patron) == m_patron.end())
	{
		error(patron.name(), " is not a patron of this library.");
		return;
	}

	int patron_index = distance(m_patron.begin(), find(m_patron.begin(), m_patron.end(), patron));
	if (m_patron[patron_index].are_fees_owed)
	{
		error(m_patron[patron_index].name, " cannot check out a book until all fees are paid.");
		return;
	}

	int book_index = distance(m_book.begin(), find(m_book.begin(), m_book.end(), book_requested));
	Date transaction_date(2018, Month::jan, 1);
	Transaction new_transaction;


	m_transaction.push_back(Transaction(m_book[book_index], m_patron[patron_index], transaction_date));
}

