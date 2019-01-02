//----------------------------------------------------------------------------
// File:	Exercise 06.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 06
//----------------------------------------------------------------------------
// Description: Striped Circle class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Striped_Circle.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 06" };
	Striped_Circle sc(Point{ 300,300 }, 200);
	sc.set_color(Color::blue);
	sc.set_fill_color(Color::green);
	win.attach(sc);

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