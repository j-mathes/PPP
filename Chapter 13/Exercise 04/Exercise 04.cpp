//----------------------------------------------------------------------------
// File:	Exercise 04.cpp
// Date:	2018-12-26
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 04
//----------------------------------------------------------------------------
// Description: Connection Points
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "ConnectionPoint.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 04" };

	Graph_lib::Rectangle r(Point{ 100,100 }, Point{ 400,375 });
	r.set_color(Color::black);
	win.attach(r);

	Point r_north = n(r);
	//Point r_north = nw(r);
	Graph_lib::Mark m1(r_north,'X');
	m1.set_color(Color::red);
	win.attach(m1);

	Point r_south = s(r);
	//Point r_south = ne(r);
	Graph_lib::Mark m2(r_south, 'X');
	m2.set_color(Color::green);
	win.attach(m2);

	Point r_east = e(r);
	//Point r_east = sw(r);
	Graph_lib::Mark m3(r_east, 'X');
	m3.set_color(Color::blue);
	win.attach(m3);

	Point r_west = w(r);
	//Point r_west = se(r);
	Graph_lib::Mark m4(r_west, 'X');
	m4.set_color(Color::black);
	win.attach(m4);

	Point r_center = center(r);
	Graph_lib::Mark m5(r_center, 'X');
	m5.set_color(Color::dark_yellow);
	win.attach(m5);

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