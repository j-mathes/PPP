//----------------------------------------------------------------------------
// File:	Exercise 16.cpp
// Date:	2019-01-13
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 16
//----------------------------------------------------------------------------
// Description: Controller class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

class Controller
{
public:
	virtual void on() {};
	virtual void off() {};
	virtual void set_level(int) {};
	virtual void show() {};

};

class Controller_a : public Controller
{
public:
	Controller_a ()
	{
		is_on = false;
		level = 0;
	}

	void on() { is_on = true; }
	void off() { is_on = false; }
	void set_level(int i) { level = i; }
	void show() 
	{ 
		string on_state = (is_on) ? "On. Level = " : "Off. Level = ";
		cout << on_state << to_string(level) << endl;
	}

private:
	bool is_on;
	int level;
};

class Controller_b : public Controller
{
public:
	Controller_b()
	{
		is_on = false;
		level = 0;
	}

	void on() { is_on = true; }
	void off() { is_on = false; }
	void set_level(int i) { level = i; }
	void show()
	{
		string on_state = (is_on) ? "Green. Brightness = " : "Red. Brightness = ";
		cout << on_state << to_string(level) << endl;
	}

private:
	bool is_on;
	int level;
};

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	Controller_a a;
	a.on();
	a.set_level(17);
	a.show();
	a.off();
	a.set_level(32);
	a.show();

	Controller_b b;
	b.on();
	b.set_level(99);
	b.show();
	b.off();
	b.set_level(-345);
	b.show();

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