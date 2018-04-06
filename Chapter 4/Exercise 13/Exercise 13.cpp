// Jared Mathes
// 2018-04-05
// Chapter 4
// Exercise 13
// Sieve of Eratosthenes - Finding Primes

#include "../../std_lib_facilities.h"

int main()
{
	const int max = 100;
	vector<int> primes(max + 1);

	primes[0] = false; 
	primes[1] = false;
	
	for (int n = 2; n <= max; ++n) primes[n] = true;
	
	for (int n = 2; n <= max; ++n) {
		if (primes[n])
			for (int k = 2 * n; k < max; k += n) primes[k] = false;
	}

	for (int n = 0; n <= max; ++n)
		if (primes[n]) cout << n << "\n";
	cout << endl;

	return 0;
}