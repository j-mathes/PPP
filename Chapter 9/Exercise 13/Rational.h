// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 13
// Rational number class
// Rational.h
#pragma once
#include "../../std_lib_facilities.h"

class Rational
{
public:
	Rational(int num, int den)
		: p(num), q(den)
	{
		normalize();
	}

	Rational()
		:p(0), q(1) {}

	void normalize();

	// operations
	Rational& operator=(const Rational& rhs)
	{
		if (this != &rhs)
		{
			this->p = rhs.p;
			this->q = rhs.q;
		}
		return *this;
	}

	int p;	// numerator
	int q;	// denominator

};
ostream& operator<<(ostream& os, Rational x);
double to_double(Rational x);
Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator-(Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);
bool operator==(Rational lhs, Rational rhs);
bool operator!=(Rational lhs, Rational rhs);