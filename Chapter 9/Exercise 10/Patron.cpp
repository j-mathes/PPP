// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 10
// Library project
// Patron.cpp

#pragma once
#include "Patron.h"

// Patron constructor
Patron::Patron(string name, string card_number, double fees_owed)
	:m_name(name), m_card_number(card_number), m_fees_owed(fees_owed)
{

}

// This will set a patron's fees regardless if there are already fees set
// Fee's must be greater than or equal to zero
void Patron::set_fees(double new_fee)
{
	if (new_fee >= 0)
	{
		m_fees_owed = new_fee;
	}
	else
	{
		error("New fee is less than zero");
	}
}

// Check to see if the patron owes any fees
bool Patron::are_fees_owed()
{
	return (m_fees_owed > 0);
}
