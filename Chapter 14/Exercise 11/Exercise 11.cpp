//----------------------------------------------------------------------------
// File:	Exercise 11.cpp
// Date:	2019-01-11
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 11
//----------------------------------------------------------------------------
// Description: Binary tree class
// https://github.com/bewuethr/stroustrup-ppp/blob/master/chapter14/chapter14_ex11.cpp
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Binary_tree.h"

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
	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 11" };

	Binary_tree bt(Point(400,40), 4);
	win.attach(bt);

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