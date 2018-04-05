/*
Jared Mathes
2018-04-04
Chapter 4
Exercise 10
Rock / Paper / Scissors
*/

#include "../../std_lib_facilities.h"

int get_computer_move(int first, int last)
{
	// implementation taken from http://www.cplusplus.com/faq/beginners/random-numbers/

	unsigned int N = (last - first <= RAND_MAX) /* Make sure the algorithm    */
		? (last - first + 1U)					/* terminates by keeping N    */
		: (RAND_MAX + 1U);						/* in rand()'s maximum range. */
	unsigned int x = (RAND_MAX + 1U) / N;
	unsigned int y = x * N;
	unsigned int r;
	do 
	{
		r = rand();
	} while (r >= y);
	
	return r / x + first;
}
int main()
{

	return 0;
}