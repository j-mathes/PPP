//----------------------------------------------------------------------------
// File:	Exercise 01.cpp
// Date:	2018-12-16
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 01
//----------------------------------------------------------------------------
// Description: Draw rectangles
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

	Point tl{ 100, 100 };							// Top left corner of window
	Simple_window win{ tl, 600, 400, "My Window" };	//make a simple window
	win.set_label("Exercise 01");

	Graph_lib::Rectangle r{ Point{30,30}, 200, 100 };
	r.set_color(Color::blue);
	win.attach(r);

	Graph_lib::Polygon p;
	p.add(Point{ 220,200 });
	p.add(Point{ 220,350 });
	p.add(Point{ 320,350 });
	p.add(Point{ 320,200 });
	p.set_color(Color::red);
	win.attach(p);

	win.wait_for_button();							// give control to the display engine

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