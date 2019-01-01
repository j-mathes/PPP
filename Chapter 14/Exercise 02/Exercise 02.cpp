//----------------------------------------------------------------------------
// File:	Exercise 02.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 02
//----------------------------------------------------------------------------
// Description: Copy a shape
// Result: error C2248: 'Graph_lib::Shape::Shape': cannot access protected member declared in class 'Graph_lib::Shape'
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

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 02" };
	Graph_lib::Closed_polyline poly;
	poly.add(Point{ 100,100 });
	poly.add(Point{ 200,200 });
	poly.add(Point{ 50,300 });

	Graph_lib::Shape shape_copy;
	shape_copy = poly;

	win.attach(poly);
	win.attach(shape_copy);

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