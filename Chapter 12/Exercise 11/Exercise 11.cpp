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
// main
// Calculate polygon vertices
// https://stackoverflow.com/questions/7198144/how-to-draw-a-n-sided-regular-polygon-in-cartesian-coordinates
// http://www.cplusplus.com/forum/general/211865/
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

	const int polygons = 12;
	int polyRadius = 50;

	Point tl{ tlX,tlY };
	Point origin{ origX,origY };

	Simple_window win{ tl,winX,winY,"Exercise 10" };

	Vector_ref<Graph_lib::Polygon> polys;

	for (int i = polygons + 2; i >= 3; i--)
	{
		constexpr double pi = 3.14159265359;
		Graph_lib::Polygon *poly = new Graph_lib::Polygon;
		for (int j = 1; j <= i; ++j)
		{
			int x = (polyRadius + (i * 4)) * cos(2 * pi * j / i) + origin.x;
			int y = (polyRadius + (i * 4)) * sin(2 * pi * j / i) + origin.y;
			poly->add(Point{ x, y });
		}
		poly->set_color(Color::black);
		int index = (i % 15 );
		poly->set_fill_color(index);
		polys.push_back(poly);
	}

	for (int i = 0; i < polys.size(); i++)
	{
		win.attach(polys[i]);
	}

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