//----------------------------------------------------------------------------
// File:	Exercise 07.cpp
// Date:	2019-01-01
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 07
//----------------------------------------------------------------------------
// Description: Striped Closed Polyline class
// https://github.com/thelastpolaris/Programming-Principles-and-Practice-Using-C-/blob/master/14/ex7.cpp
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Striped_Closed_Polyline.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 07" };
	Striped_Closed_Polyline scp{};
	scp.add(Point{ 100,100 });
	scp.add(Point{ 300,280 });
	scp.add(Point{ 200,280 });
	scp.add(Point{ 50,200 });
	scp.add(Point{ 90,150 });
	scp.set_color(Color::blue);
	scp.set_fill_color(Color::green);
	win.attach(scp);

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