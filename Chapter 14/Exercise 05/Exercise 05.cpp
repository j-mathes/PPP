//----------------------------------------------------------------------------
// File:	Exercise 05.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 05
//----------------------------------------------------------------------------
// Description: Striped Rectangle class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Striped_Rectangle.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 01" };
	Striped_Rectangle sr(Point{ 50,50 }, 300, 100);
	sr.set_color(Color::blue);
	sr.set_fill_color(Color::green);
	win.attach(sr);

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