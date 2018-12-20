//----------------------------------------------------------------------------
// File:	Exercise 10.cpp
// Date:	2018-12-20
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 10
//----------------------------------------------------------------------------
// Description: File diagram from 12.8
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

	int tlX = 50;
	int tlY = 50;
	int winX = 800;
	int winY = 800;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Exercise 10" };

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