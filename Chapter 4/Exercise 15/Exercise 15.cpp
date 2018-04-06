// Jared Mathes
// 2018-04-05
// Chapter 4
// Exercise 15
// Find the first n primes

#include "../../std_lib_facilities.h"

vector<int> primes;

int main()
{
	primes.push_back(2);
	bool is_prime;
	int number_of_primes{ 0 };
	int counter{ 0 };

	cout << "How many prime numbers do you want? > ";
	cin >> number_of_primes;
	cout << "\n";

	for (int i = 3; counter < number_of_primes - 1; ++i)
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
		{
			primes.push_back(i);
			++counter;
		}
	}

	for (int x : primes)
	{
		cout << x << '\n';
	}
	return 0;
}