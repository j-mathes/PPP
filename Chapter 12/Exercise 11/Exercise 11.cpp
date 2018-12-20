//----------------------------------------------------------------------------
// File:	Exercise 11.cpp
// Date:	2018-12-20
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 11
//----------------------------------------------------------------------------
// Description: Series of polygons
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

//----------------------------------------------------------------------------
// Calculate polygon vertices
// https://stackoverflow.com/questions/7198144/how-to-draw-a-n-sided-regular-polygon-in-cartesian-coordinates
//----------------------------------------------------------------------------
Closed_polyline * nPolygon(Point origin, int radius, int sides)
{
	Closed_polyline * p = new Closed_polyline();
	const double pi = 3.141592653;

	for (size_t i = 0; i < sides; i++)
	{
		int x = radius * cos(2 * pi * i / sides) + origin.x;
		int y = radius * sin(2 * pi * i / sides) + origin.y;
		p->add(Point{ x, y });
	}

	return p;
}

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

	int origX = winX / 2;
	int origY = winY / 2;

	const int polygons = 8;
	int polyRadius = 30;

	Point tl{ tlX,tlY };
	Point origin{ origX,origY };

	Simple_window win{ tl,winX,winY,"Exercise 10" };

	for (int i = polygons + 3; i >= 3; i--)
		win.attach(nPolygon(origin, polyRadius + i, i));

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