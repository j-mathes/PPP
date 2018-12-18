//----------------------------------------------------------------------------
// File:	Exercise 02.cpp
// Date:	2018-12-18
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 02
//----------------------------------------------------------------------------
// Description: Rectangle and Text
//----------------------------------------------------------------------------

//#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	using namespace Graph_lib;

	Point tl{ 50,50 };
	Simple_window win{ tl, 600, 400, "Exercise 02" };

	Graph_lib::Rectangle r{ Point{30,30}, 100, 30 };
	r.set_color(Color::black);

	Text t{ Point{60,50}, "Howdy!" };
	t.set_color(Color::black);

	win.attach(r);
	win.attach(t);

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