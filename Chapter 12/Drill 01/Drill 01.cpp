//----------------------------------------------------------------------------
// File:	Drill 01.cpp
// Date:	2018-12-16
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Drill 01
//----------------------------------------------------------------------------
// Description: Get acquainted with simple graphical output tools
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	using namespace Graph_lib;

	Point tl{ 100, 100 };							// Top left corner of window
	Simple_window win{ tl, 600, 400, "My Window" };	//make a simple window

	win.wait_for_button();							// give control to the display engine

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