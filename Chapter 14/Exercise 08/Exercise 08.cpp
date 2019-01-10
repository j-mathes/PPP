//----------------------------------------------------------------------------
// File:	Exercise 08.cpp
// Date:	2019-01-09
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 08
//----------------------------------------------------------------------------
// Description: Octagon Class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Octagon.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 08" };

	Octagon o{Point{ 300,300 }, 150};
	o.set_color(Color::dark_blue);
	o.set_fill_color(Color::cyan);
	win.attach(o);
	cout << "Octagon Center: " << o.center().x << "," << o.center().y << endl;
	cout << "Octagon Radius: " << o.radius() << endl;
	win.wait_for_button();

	o.set_radius(50);
	cout << "Octagon Radius: " << o.radius() << endl;
	win.wait_for_button();

	o.move(60, 60);
	cout << "Octagon Center: " << o.center().x << "," << o.center().y << endl;
	win.wait_for_button();

	o.set_style(Line_style(Line_style::dashdotdot,5));
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