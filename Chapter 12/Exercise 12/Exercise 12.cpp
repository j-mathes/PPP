//----------------------------------------------------------------------------
// File:	Exercise 12.cpp
// Date:	2018-12-21
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 12
//----------------------------------------------------------------------------
// Description: Star shape based on super ellipse
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

	const int tlX = 50;
	const int tlY = 50;
	const int winX = 800;
	const int winY = 800;

	int origX = winX / 2;
	int origY = winY / 2;

	const int shapePoints = 7;
	const int shapeRadius = 50;

	constexpr double pi = 3.14159265359;

	Point tl{ tlX,tlY };
	Point origin{ origX,origY };

	Simple_window win{ tl,winX,winY,"Exercise 12" };

	vector<Point> pts;
	for (int i = 1; i <= shapePoints; i++)
	{
		int x = static_cast<int> (shapeRadius * cos(2 * pi * i / shapePoints) + origin.x);
		int y = static_cast<int> (shapeRadius * sin(2 * pi * i / shapePoints) + origin.y);
		pts.push_back(Point{ x,y });
	}

	Graph_lib::Lines shapeLines;
	for (int i = 0; i < pts.size(); ++i)
	{
		for (int j = 0; j < pts.size(); ++j)
		{
			shapeLines.add(pts[i], pts[j]);
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