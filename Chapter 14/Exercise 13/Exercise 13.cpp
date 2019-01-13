//----------------------------------------------------------------------------
// File:	Exercise 13.cpp
// Date:	2019-01-13
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 13
//----------------------------------------------------------------------------
// Description: Binary tree with parameters for lines
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Binary_tree_13.h"

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
	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 13" };

	Binary_tree_13 btu(Point(300, 40), 4, Connector_type::arrow_up);
	win.attach(btu);

	Binary_tree_13 btd(Point(500, 300), 4, Connector_type::arrow_down);
	win.attach(btd);

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