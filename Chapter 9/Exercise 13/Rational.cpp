// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 13
// Rational number class
// Rational.cpp
#include "Rational.h"

int gcd(int x, int y)
// greatest common denominator
// Euclid's algorithm (using remainder)
{
	x = abs(x);	// don't get confused by negative values
	y = abs(y);
	while (y) {
		int t = y;
		y = x % y;
		x = t;
	}
	return x;
}

void Rational::normalize()
{
	if (q == 0) error("Denominator is zero");
	if (q < 0)
	{
		q = -q;
		p = -p;
	}
	int n = gcd(p, q);
	if (n > 1)
	{
		p /= n;
		q /= n;
	}
}

// utilities

ostream& operator<<(ostream& os, Rational x)
{
	return cout << '(' << x.p << '/' << x.q << ')';
}

bool operator==(Rational lhs, Rational rhs)
{
	return lhs.p * rhs.q == lhs.q * rhs.p;
}

bool operator!=(Rational lhs, Rational rhs)
{
	return !(lhs == rhs);
}

double to_double(Rational x)
{
	return double(x.p) / x.q;
}

Rational operator+(Rational lhs, Rational rhs)
{
	Rational r(lhs.p * rhs.q + lhs.q * rhs.p, lhs.q * rhs.q);
	r.normalize();
	return r;
}

Rational operator-(Rational lhs, Rational rhs)
{
	Rational r(lhs.p * rhs.q - lhs.q * rhs.p, lhs.q * rhs.q);
	r.normalize();
	return r;
}

Rational operator-(Rational rhs)
{
	return Rational(-rhs.p, rhs.q);
}

Rational operator*(Rational lhs, Rational rhs)
{
	Rational r(lhs.p * rhs.p, lhs.q * rhs.q);
	r.normalize();
	return r;
}

Rational operator/(Rational lhs, Rational rhs)
{
	Rational r(lhs.p * rhs.q, lhs.q * rhs.p);
	r.normalize();
	return r;
}
