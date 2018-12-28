//----------------------------------------------------------------------------
// File:	Exercise 08.cpp
// Date:	2018-12-27
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 08
//----------------------------------------------------------------------------
// Description: Regular Regular_hexagon class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "Regular_hexagon.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	using namespace Graph_lib;

	const int tlX = 50;
	const int tlY = 50;
	const int winX = 600;
	const int winY = 600;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 08" };

	Regular_hexagon h(Point{ 300,300 }, 100);
	h.set_color(Color::black);
	win.attach(h);

	win.wait_for_button();

	Simple_window win1{ tl,winX,winY,"Chapter 13, Exercise 09 & 16" };

	vector<Point> centers;
	int s = 50;
	for (int i = 0; i < (win1.y_max() / (sqrt(3) / 2.0*s))+s; ++i) {
		for (int j = 0; j < (win1.x_max() / 3.0 / s)+s; ++j) {
			int dx = 0;
			if (i % 2 == 0) dx = 0;
			else dx = static_cast<int>(round(1.5*s));
			centers.push_back(Point(j * 3 * s + dx, static_cast<int>(i*sqrt(3) / 2 * s)));
		}
	}

	Vector_ref<Regular_hexagon> hexagons;
	for (size_t i = 0; i < centers.size(); ++i)
	{
		hexagons.push_back(new Regular_hexagon(centers[i], s));
		hexagons[hexagons.size() - 1].set_color(Color::black);
		win1.attach(hexagons[hexagons.size() - 1]);
	}

	win1.wait_for_button();
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