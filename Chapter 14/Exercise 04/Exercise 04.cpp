//----------------------------------------------------------------------------
// File:	Exercise 04.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 04
//----------------------------------------------------------------------------
// Description: Immobile Circle class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include"../Classes/Immobile_Circle.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 04" };

	Immobile_Circle ic(Point{ 300,300 }, 125);
	ic.set_color(Color::red);
	win.attach(ic);
	ic.move(300, 125);

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