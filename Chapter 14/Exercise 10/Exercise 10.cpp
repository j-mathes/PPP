//----------------------------------------------------------------------------
// File:	Exercise 10.cpp
// Date:	2019-01-10
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 10
//----------------------------------------------------------------------------
// Description: Pseudo_window class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Pseudo_window.h"
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
	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 10" };

	Pseudo_window pw1(Point{ 50,50 }, 150, 200, "Window #1");
	win.attach(pw1);

	Pseudo_window pw2(Point{ 300,350 }, 230, 400, "Window #2");
	win.attach(pw2);
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