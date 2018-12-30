//----------------------------------------------------------------------------
// File:	Exercise 12.cpp
// Date:	2018-12-29
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 12
//----------------------------------------------------------------------------
// Description: Circle with moving mark
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/ConnectionPoint.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 12" };
	Graph_lib::Circle c(Point{ winX / 2,winY / 2 }, 150);
	c.set_color(Color::black);
	win.attach(c);

	std::srand(time(NULL));
	while (true)
	{
		int rn = rand() % 360;
		Mark m(point_on_circle(c, rn), 'X');
		m.set_color(Color::red);
		win.attach(m);
		win.wait_for_button();
	}

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