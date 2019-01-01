//----------------------------------------------------------------------------
// File:	Exercise 01.cpp
// Date:	2018-12-31
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 01
//----------------------------------------------------------------------------
// Description: Smiley and Frowny classes with Hats classes.
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Smiley.h"
#include "../Classes/Frowny.h"
#include "../Classes/Smiley_Hat.h"
#include "../Classes/Frowny_Hat.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	using namespace Graph_lib;
	const int tlX = 50;
	const int tlY = 50;
	const int winX = 800;
	const int winY = 800;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 01" };

	Smiley s1(Point{ 200,200 }, 150);
	Frowny f1(Point{ 600,200 }, 150);
	Smiley_Hat s2(Point{ 200,600 }, 100);
	Frowny_Hat f2(Point{ 500,700 }, 125);

	s1.set_color(Color::dark_green);
	f1.set_color(Color::dark_blue);
	s2.set_color(Color::dark_magenta);
	f2.set_color(Color::dark_blue);

	win.attach(s1);
	win.attach(f1);
	win.attach(s2);
	win.attach(f2);

	win.wait_for_button();

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