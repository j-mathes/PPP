// Jared Mathes
// 2018-08-06
// Chapter 9
// Exercise 09
// Library project
// Library.cpp

#pragma once
#include "Library.h"

bool operator==(const Book& a, const Book& b)
{
	return (a.ISBN() == b.ISBN());
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

bool operator==(const Patron& a, const Patron& b)
{
	return(a.card_number() == b.card_number());
}

bool operator!=(const Patron& a, const Patron& b)
{
	return !(a == b);
}

Library::Transaction::Transaction(Book b, Patron p, Date d)
	: book(b), patron(p), date(d)
{

}

void Library::add_book(const Book& book_to_add)
{
	m_book.push_back(book_to_add);
}

void Library::add_patron(const Patron& patron_to_add)
{
	m_patron.push_back(patron_to_add);
}

void Library::check_out_book(Book& book_requested, const Patron& patron, const Date& transaction_date)
{
	bool book_exists = false;
	int book_index = 0;
	for (size_t i=0; i < m_book.size(); ++i)
	{
		if (m_book[i] == book_requested)
		{
			book_exists = true;
			book_index = i;
			break;
		}
	}
	if (!book_exists)
	{
		error(book_requested.title(), " is not a book this library carries.");
		return;
	}

	bool patron_exists = false;
	int patron_index = 0;
	for (size_t i = 0; i < m_patron.size(); ++i)
	{
		if (m_patron[i] == patron)
		{
			patron_exists = true;
			patron_index = i;
			break;
		}
	}
	if (!patron_exists)
	{
		error(patron.name(), " is not a patron of this library.");
		return;
	}

	if (m_patron[patron_index].are_fees_owed())
	{
		error(m_patron[patron_index].name(), " cannot check out a book until all fees are paid.");
		return;
	}

	m_transaction.push_back(Transaction(m_book[book_index], m_patron[patron_index], transaction_date));
}

vector <Patron> Library::patrons_who_owe_fees() const
{
	vector <Patron> patrons_with_fees;

	for (auto &i : m_patron)
	{
		if (i.fees_owed() > 0)
			patrons_with_fees.push_back(i);
	}

	return patrons_with_fees;
}
