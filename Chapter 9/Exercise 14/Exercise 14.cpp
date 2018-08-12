// Jared Mathes
// 2018-08-11
// Chapter 9
// Exercise 14
// Money class

#include "../../std_lib_facilities.h"

constexpr char currency{ '$' };

long int iround(double n)
{
	return (n < 0.0) ? (n - 0.5) : (n + 0.5);
}

class Money
{
public:
	Money(long int units, long int cents);
	Money(long int amount);
	Money();

	long int amount() const { return m_amount; };
	long int units() const { return m_amount / 100; };
	long int cents() const { return m_amount % 100; };
	
private:
	long int m_amount;
};

// constructors
Money::Money(long int units, long int cents)
	:m_amount{ units * 100 + cents } {};

Money::Money(long int amount)
	:m_amount{ amount } {};

Money::Money()
	:m_amount{0} {};

// operators
Money operator-(const Money& rhs)
{
	return Money{ -rhs.amount() };
}

Money operator+(const Money& lhs, const Money& rhs)
{
	return Money{ lhs.amount() + rhs.amount() };
}

Money operator-(const Money& lhs, const Money& rhs)
{
	return Money{ lhs.amount() - rhs.amount() };
}

Money operator*(const Money& lhs, double rhs)
{
	return Money{ iround(lhs.amount()*rhs) };
}

Money operator*(double lhs, const Money& rhs)
{
	return Money{ iround(lhs*rhs.amount()) };
}

Money operator/(const Money& lhs, double rhs)
{
	if (rhs != 0)
	{
		return Money(iround(lhs.amount() / rhs));
	}
	else
	{
		error("divide by zero");
	}
}

double operator/(const Money& lhs, const Money& rhs)
{
	if (rhs.amount() != 0)
	{
	return (double(lhs.amount()) / rhs.amount());
	}
	else
	{
		error("divide by zero");
	}
}

bool operator==(const Money& lhs, const Money& rhs)
{
	return (lhs.amount() == rhs.amount());
}

bool operator!=(const Money& lhs, const Money& rhs)
{
	return (lhs.amount() != rhs.amount());
}

ostream& operator<<(ostream& os, const Money& money)
{
	os << currency << money.units() << '.';
	if (abs(money.cents()) < 10) os << '0';
	os << abs(money.cents());
	return os;
}

istream& operator>>(istream& is, Money& money)
{
	long int units{ 0 };
	char cur, dot;
	char d, u;

	is >> cur >> units >> dot >> d >> u;
	if (!is) return is;
	if (cur != currency || dot != '.' || !isdigit(d) || !isdigit(u))
	{
		is.clear(ios_base::failbit);
		return is;
	}

	int cents{ (d - '0') * 10 + (u - '0') };
	if (units < 0) cents = -cents;
	money = Money{ (units * 100) + cents };

	return is;
}

int main()
try
{
	// Test Money*double, double*Money, Money/Money, Money/double, Money-Money and <<

	Money budget{ 1000000,0 };
	Money wage{ 1500,0 };
	long int months{ 18 };
	long int workers{ iround(budget / (wage*months)) };
	Money surplus{ budget - (workers*wage*months) };
	cout << "The project's budget ascends to " << budget
		<< " and it will be developed during " << months << " months.\n"
		<< "Each developer get " << wage << " per month. "
		<< "So we can hire " << workers << " developers.\n"
		<< "The spare budget will be " << surplus << ".\n";

	cout << '\n';

	// Test Money*double, Money+Money and <<
	Money product{ 134,0 };
	double vat = 0.21;
	Money total{ product + (product*vat) };
	cout << "You have bought and paid by transference " << product
		<< " for a product. But you forgot the VAT (" << vat * 100
		<< "%).\n" << "With VAT applied the product costs " << total
		<< " so you debt " << product - total << '\n';

	cout << '\n';

	// Test and justify Money/Money
	Money after_tax{ 41,82 };
	Money before_tax{ 34,56 };
	double tax{ (after_tax / before_tax) - 1 };
	cout << "A product with a final price of " << after_tax << " and a price"
		<< " before taxes of " << before_tax << "\nhas been applied a "
		<< tax * 100 << "% of taxes (" << after_tax - before_tax << ")\n";

	cout << '\n';

	// Test >> and << operators;
	cout << "Write some quantities (examples: $123.04 or $-10.10, two digits"
		<< " for cents are mandatory. Quit with Ctrl+D).\n> ";
	Money input{ 0 };
	while (cin) {
		cin >> input;
		if (cin.eof()) break;
		if (cin.fail()) {
			cout << "Bad input format\n> ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cout << '\t' << input << "\n> ";
		}
	}



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