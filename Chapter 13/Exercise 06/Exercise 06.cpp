//----------------------------------------------------------------------------
// File:	Exercise 06.cpp
// Date:	2018-12-27
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 06
//----------------------------------------------------------------------------
// Description: Class Diagram
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "Box.h"
#include "ConnectionPoint.h"
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

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 06" };

	Box b1(Point{ 200,200 }, 300, 100, "SomeFile.h");
	b1.set_color(Color::black);
	win.attach(b1);

	Box b2(Point{ 300,500 }, 300, 100, "SomeFile.cpp");
	b2.set_color(Color::black);
	win.attach(b2);

	Arrow a(s(b1), n(b2), 5);
	a.set_color(Color::red);
	win.attach(a);

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