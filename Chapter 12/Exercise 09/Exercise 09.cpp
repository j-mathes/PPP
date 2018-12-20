//----------------------------------------------------------------------------
// File:	Exercise 09.cpp
// Date:	2018-12-20
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 09
//----------------------------------------------------------------------------
// Description: Display bitmap picture
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

	Simple_window win{ tl,winX,winY,"Exercise 09" };

	Image pic{ Point{100,100},"A.jpg" };
	win.attach(pic);

	Text txt{ Point{100,50}, "A.jpg" };
	txt.set_color(Color::black);
	win.attach(txt);

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