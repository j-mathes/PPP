//----------------------------------------------------------------------------
// File:	Exercise 03.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 03
//----------------------------------------------------------------------------
// Description: Define an abstract class and try to define an object of that type. What happens?
// Result: error C2248: 'A::A': cannot access protected member declared in class 'A'
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

class A
{
public:
protected:
	// Constructor defined as protected makes class abstract
	A(){}
private:
};

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	A new_object;

	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}