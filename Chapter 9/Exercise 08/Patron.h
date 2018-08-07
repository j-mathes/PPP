// Jared Mathes
// 2018-08-06
// Chapter 9
// Exercise 08
// Library project
// Patron.h

#pragma once
#include "../../std_lib_facilities.h"
class Patron
{
public:
	Patron(string name, string card_number, double fees_owed);
	string name() const { return m_name; }
	string card_number() const { return m_card_number; }
	double fees_owed() const { return m_fees_owed; }
	void set_fees(double);
	bool are_fees_owed();
private:
	string m_name;
	string m_card_number;
	double m_fees_owed;
};

