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