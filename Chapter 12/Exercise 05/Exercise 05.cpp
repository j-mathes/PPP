//----------------------------------------------------------------------------
// File:	Exercise 05.cpp
// Date:	2018-12-18
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 05
//----------------------------------------------------------------------------
// Description: Rectangle With Border
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
	int winX = 600;
	int winY = 400;
	int frameWidth = 30;

	Point tl{ tlX,tlY };
	Point frameTl{ tlX - (int)(frameWidth / 2) + 1, tlY - (int)(frameWidth / 2) + 1 };

	Simple_window win{ tl,winX,winY,"Exercise 05" };
	Graph_lib::Rectangle r{ tl, (int)(winX * .66), (int)(winY * .75) };
	Graph_lib::Rectangle fr{ frameTl, (int)(winX * .66) + frameWidth, (int)(winY * .75) + frameWidth };
	r.set_color(Color::black);
	fr.set_color(Color::red);
	fr.set_style(Line_style(Line_style::solid, frameWidth));

	win.attach(r);
	win.wait_for_button();

	win.attach(fr);
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