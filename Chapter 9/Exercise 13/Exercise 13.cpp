// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 13
// Rational number class

#include "Rational.h"

int main()
try
{
	Rational r1(4, 2);
	cout << r1 << "==" << to_double(r1) << '\n';
	Rational r2(42, 24);
	cout << r2 << "==" << to_double(r2) << '\n';
	cout << r1 + r2 << "==" << to_double(r1 + r2) << "==" << to_double(r1) + to_double(r2) << '\n';
	cout << r1 - r2 << "==" << to_double(r1 - r2) << "==" << to_double(r1) - to_double(r2) << '\n';
	cout << -r2 << "==" << to_double(-r2) << "==" << -to_double(r2) << '\n';
	cout << r1 * r2 << "==" << to_double(r1*r2) << "==" << to_double(r1)*to_double(r2) << '\n';
	cout << r1 / r2 << "==" << to_double(r1 / r2) << "==" << to_double(r1) / to_double(r2) << '\n';
	if (r2 == Rational(14, 8)) cout << "equal\n";
	if (r2 != Rational(14, 8)) cout << "not equal\n";
	Rational(3, 0);


	keep_window_open("~");
	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	keep_window_open("~");
}

catch (...)
{
	cerr << "exception\n";
	keep_window_open("~");
}