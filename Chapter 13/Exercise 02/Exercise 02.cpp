//----------------------------------------------------------------------------
// File:	Exercise 02.cpp
// Date:	2018-12-24
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 02
//----------------------------------------------------------------------------
// Description: Define and test a Box class with rounded corners
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "Box.h"

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
	const int winY = 1000;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 02" };

	Graph_lib::Box b1{ Point{300,300}, 200, 300, 10 };
	Graph_lib::Box b2{ Point{50,124}, 324, 350, 31};
	Graph_lib::Box b3{ Point{502,800}, 200, 10, 0 };
	b1.set_color(Color::dark_green);
	b2.set_color(Color::black);
	b3.set_color(Color::red);
	win.attach(b1);
	win.attach(b2);
	win.attach(b3);
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