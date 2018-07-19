#include "my.h"

int foo = 7;	// should be defined outside of main so it has global scope to match extern declaration in my.h

int main()
{
	print_foo();
	print(99);

	return 0;
}