//----------------------------------------------------------------------------
// File:	Drill.cpp
// Date:	2018-12-31
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Drill
//----------------------------------------------------------------------------
// Description: OOP Language Features
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

class B1
{
public:
	void f() { cout << "B1::f" << endl; }
	virtual void vf() { cout << "B1::vf" << endl; }
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void f() { cout << "D1::f" << endl; }
	void vf() { cout << "D1::vf" << endl; }
};

class D2 : public D1
{
public:
	void pvf() { cout << "D2::pvf" << endl; }
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	void pvf() { cout << s << endl; };
	string s;
};

class D22 : public B2
{
public:
	void pvf() { cout << i << endl; }
	int i;
};

void f(B2& ref_B2) { ref_B2.pvf(); }

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	//B1 test_B1;
	//test_B1.f();
	//test_B1.vf();

	//D1 test_D1;
	//test_D1.f();
	//test_D1.vf();

	//B1& test_ref_B1 = test_D1;
	//test_ref_B1.f();
	//test_ref_B1.vf();

	D2 test_D2;
	test_D2.f();
	test_D2.vf();
	test_D2.pvf();

	D21 test_D21;
	D22 test_D22;
	test_D21.s = "D21.s";
	test_D22.i = 22;

	f(test_D21);
	f(test_D22);

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