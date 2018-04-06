// Jared Mathes
// 2018-04-06
// Chapter 4
// Exercise 18
// Solve a quadratic equation

#include "../../std_lib_facilities.h"

int main()
{
	cout << "This program will solve a quadratic equation in the form of\n\n";
	cout << "ax^2 + bx + c = 0\n\n";
	cout << "Input a value for a > ";
	double a;
	cin >> a;

	cout << "\nInput a value for b > ";
	double b;
	cin >> b;

	cout << "\nInput a value for c > ";
	double c;
	cin >> c;

	double x1{ 0 };
	double x2{ 0 };

	if (a==0 && b==0)
	{
		cout << "\n\nSorry, those aren't valid entries for the equation.\n";
	}
	else if (a==0 && b!=0)
	{
		x1 = -(c / b);
		cout << "\nOne root = " << x1 << '\n';
	}
	else
	{
		if (((b*b) - (4 * a*c)) < 0)
		{
			cout << "Not a real root.\n";
		}
		else
		{
			double delta = (b*b) - (4 * a*c);
			x1 = -b - sqrt(delta) / (2 * a);
			x2 = -b + sqrt(delta) / (2 * a);

			cout << "\nFirst root  = " << x1;
			cout << "\nSecond root = " << x2;
			cout << '\n';
		}
	}

	return 0;
}