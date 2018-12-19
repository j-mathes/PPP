//----------------------------------------------------------------------------
// File:	Exercise 08.cpp
// Date:	2018-12-19
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 08
//----------------------------------------------------------------------------
// Description: Olympic Rings
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	using namespace Graph_lib;

	int tlX = 50;
	int tlY = 50;
	int winX = 800;
	int winY = 800;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Exercise 08" };

	Circle c1{ Point{100,200},40 };
	Circle c2{ Point{200,200},40 };
	Circle c3{ Point{300,200},40 };
	Circle c4{ Point{150,240},40 };
	Circle c5{ Point{250,240},40 };

	c1.set_color(Color::blue);
	c2.set_color(Color::black);
	c3.set_color(Color::red);
	c4.set_color(Color::yellow);
	c5.set_color(Color::green);

	c1.set_style(Line_style(Line_style::solid, 5));
	c2.set_style(Line_style(Line_style::solid, 5));
	c3.set_style(Line_style(Line_style::solid, 5));
	c4.set_style(Line_style(Line_style::solid, 5));
	c5.set_style(Line_style(Line_style::solid, 5));

	win.attach(c1);
	win.attach(c2);
	win.attach(c3);
	win.attach(c4);
	win.attach(c5);

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