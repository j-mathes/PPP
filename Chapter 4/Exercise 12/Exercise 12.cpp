// Jared Mathes
// 2018-04-05
// Chapter 4
// Exercise 12
// Primes up to max

#include "../../std_lib_facilities.h"

vector<int> primes;

int main()
{
	primes.push_back(2);
	bool is_prime;
	int max{ 0 };

	cout << "Enter the number up to which you want to find prime numbers. > ";
	cin >> max;
	cout << "\n";

	for (int i = 3; i <= max; ++i)
	{
		is_prime = true;
		for (int x : primes)
		{
			if (i % x == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			primes.push_back(i);
	}

	for (int x : primes)
	{
		cout << x << '\n';
	}
	return 0;
}