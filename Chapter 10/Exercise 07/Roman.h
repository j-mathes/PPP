// Jared Mathes
// 2018-08-25
// Chapter 10
// Exercise 07
// Simple Calculator
// Roman Numerals
// Roman Numeral class information
#pragma once

#include "../../std_lib_facilities.h"

#ifndef ROMAN_H
#define ROMAN_H

namespace Roman
{

	constexpr size_t lut_end{ 100 };
	constexpr int max_roman{ 4999 };			// max int representable with implemented notation
	constexpr int min_roman{ 1 };				// min int

	class Not_a_particle { };			// Exception when get_particle or lut_idx doesn't
										// found a particle
	class Not_roman { };				// Exception when Roman_int initialized with
										// value out of [min, max]

	struct lut_row
	{
		string particle;				// particle of roman number
		int value;						// associated decimal value
		size_t next;					// next particle to look ahead after this particle
	};

	class Roman_int
	{
	public:
		Roman_int(string s);			// Initialize with a roman numeral
		Roman_int(int a = 1);				// Initialize with an integer

		string value() const;			// Return a string with the roman numeral representation
		int as_int() const { return m_value; }	// Return the int value

	private:
		int m_value;
	};

	size_t lut_idx(string& particle, size_t start);
	string get_particle(istream& is, size_t start);
	int parse_roman(istream& is);
	string compose_roman(int a);
	ostream& operator<<(ostream& os, const Roman_int& rhs);
	istream& operator>>(istream& is, Roman_int& rhs);

	Roman_int operator+(const Roman_int& lhs, const Roman_int& rhs);
	Roman_int operator-(const Roman_int& lhs, const Roman_int& rhs);
	Roman_int operator*(const Roman_int& lhs, const Roman_int& rhs);
	Roman_int operator/(const Roman_int& lhs, const Roman_int& rhs);
	Roman_int operator%(const Roman_int& lhs, const Roman_int& rhs);

	Roman_int& operator+=(Roman_int& lhs, const Roman_int& rhs);
	Roman_int& operator-=(Roman_int& lhs, const Roman_int& rhs);
	Roman_int& operator*=(Roman_int& lhs, const Roman_int& rhs);
	Roman_int& operator/=(Roman_int& lhs, const Roman_int& rhs);
	Roman_int& operator%=(Roman_int& lhs, const Roman_int& rhs);
}										// close namespace
#endif