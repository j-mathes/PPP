//----------------------------------------------------------------------------
// File:	Exercise 11.cpp
// Date:	2018-12-29
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 11
//----------------------------------------------------------------------------
// Description: Ellipse with axis
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/ConnectionPoint.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 11" };
	Graph_lib::Ellipse ellipse1(Point{ winX/2,winY/2 }, 150, 100);
	ellipse1.set_color(Color::black);
	win.attach(ellipse1);

	Graph_lib::Axis xa{ Axis::x, 
		Point{ellipse1.center().x - ellipse1.major() - 50, ellipse1.center().y},
		400,
		8
	};
	xa.set_color(Color::dark_green);
	win.attach(xa);

	Graph_lib::Axis ya{ Axis::y,
	Point{ellipse1.center().x, ellipse1.center().y + ellipse1.minor() + 50},
	300,
	6
	};
	ya.set_color(Color::dark_magenta);
	win.attach(ya);

	Mark f1(ellipse1.focus1(), '1');
	f1.set_color(Color::red);
	win.attach(f1);

	Mark f2(ellipse1.focus2(), '2');
	f2.set_color(Color::dark_yellow);
	win.attach(f2);

	Mark p1(point_on_ellipse(ellipse1,75), 'X');
	p1.set_color(Color::blue);
	win.attach(p1);

	Open_polyline opl;
	opl.add(f1.point(0));
	opl.add(p1.point(0));
	opl.add(f2.point(0));
	opl.set_color(Color::cyan);
	win.attach(opl);

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