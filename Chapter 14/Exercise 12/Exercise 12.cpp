//----------------------------------------------------------------------------
// File:	Exercise 12.cpp
// Date:	2019-01-13
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 12
//----------------------------------------------------------------------------
// Description: Binary tree class - virtual function
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Binary_tree_12.h"
#include "../Classes/Binary_tree_12_square.h"

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
	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 12" };

	Binary_tree_12 bt(Point(400, 40), 4);
	win.attach(bt);

	Binary_tree_12_square bts(Point(500, 500), 3);
	win.attach(bts);

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