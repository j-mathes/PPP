//----------------------------------------------------------------------------
// File:	Exercise 03.cpp
// Date:	2018-12-26
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 03
//----------------------------------------------------------------------------
// Description: Define and test an Arrow class
// https://stackoverflow.com/questions/10316180/how-to-calculate-the-coordinates-of-a-arrowhead-based-on-the-arrow
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "Arrow.h"

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
	const int winY = 1000;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 03" };
	Graph_lib::Arrow a1(Point{ 50,100 }, Point{ 500,450 }, 10);
	a1.set_color(Color::red);
	win.attach(a1);

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