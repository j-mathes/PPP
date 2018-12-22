//----------------------------------------------------------------------------
// File:	Exercise 13.cpp
// Date:	2018-12-21
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 13
//----------------------------------------------------------------------------
// Description: Star shape based on super ellipse with colors
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

//----------------------------------------------------------------------------
// sgn - determine return value based on input
//----------------------------------------------------------------------------
int sgn(double d) {

	if (d < 0)
		return -1;
	if (d == 0)
		return 0;
	if (d > 0)
		return 1;
	// exception
	error("sgn: something gone wrong\n");
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

	constexpr double pi = 3.14159265359;

	// Super ellipse parameters

	double a = 250;
	double b = 250;
	double m = 1.5;
	double n = 1.5;

	double precision = 0.2;

	Point tl{ tlX,tlY };
	Point origin{ origX,origY };

	Simple_window win{ tl,winX,winY,"Exercise 12" };

	vector<Point> pts;
	Point temp;
	Point point;
	for (double d = -1.0; d < 1.0; d += precision) {
		double t = d * pi;
		int x = static_cast<int> (a * pow(abs(cos(t)), 2.0 / m) * sgn(cos(t)));
		int y = static_cast<int> (b * pow(abs(sin(t)), 2.0 / n) * sgn(sin(t)));

		point = Point{ x + origX, y + origY };
		if (temp != point) pts.push_back(point); // Check for duplicates
		temp = point;
	}

	Graph_lib::Lines shapeLines;
	int count = 0;
	for (size_t i = 0; i < pts.size(); ++i)
	{
		for (size_t j = 0; j < pts.size(); ++j)
		{
			if (i != j)
			{
				shapeLines.set_color(count % 15);
				shapeLines.add(pts[i], pts[j]);
				count++;
			}
		}
	}

	win.attach(shapeLines);

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