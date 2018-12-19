//----------------------------------------------------------------------------
// File:	Exercise 06.cpp
// Date:	2018-12-18
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 06
//----------------------------------------------------------------------------
// Description: Doesn't Fit
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

	int tlX = 50;
	int tlY = 50;
	int winX = 6000;
	int winY = 4000;
	int rectWidth = 900;
	int rectHeight = 900;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Exercise 06" };
	Graph_lib::Rectangle r{ tl, rectWidth, rectHeight };

	r.set_color(Color::black);

	win.attach(r);
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