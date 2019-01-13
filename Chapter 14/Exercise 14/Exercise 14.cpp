//----------------------------------------------------------------------------
// File:	Exercise 14.cpp
// Date:	2019-01-13
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 14
//----------------------------------------------------------------------------
// Description: Binary tree with labels
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Binary_tree_14.h"

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
	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 14" };

	Binary_tree_14 btu(Point(300, 40), 4, Connector_type::arrow_down);
	win.attach(btu);

	btu.set_node_label("l", "Root Node");
	btu.set_node_label("lr", "l,r");
	btu.set_node_label("lll", "l,l,l");

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