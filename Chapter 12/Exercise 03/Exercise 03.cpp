//----------------------------------------------------------------------------
// File:	Exercise 03.cpp
// Date:	2018-12-18
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 03
//----------------------------------------------------------------------------
// Description: Write text to window
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

	Point tl{ 50,50 };
	Simple_window win{ tl, 600, 400, "Exercise 03" };

	Text i1{ Point{50,300}, "J" };
	Text i2{ Point{150,300}, "C" };
	Text i3{ Point{250,300}, "M" };

	i1.set_color(Color::blue);
	i2.set_color(Color::red);
	i3.set_color(Color::green);

	i1.set_font_size(150);
	i2.set_font_size(150);
	i3.set_font_size(150);

	i1.set_style(Line_style(Line_style::solid, 5));
	i2.set_style(Line_style(Line_style::solid, 5));
	i3.set_style(Line_style(Line_style::solid, 5));

	win.attach(i1);
	win.attach(i2);
	win.attach(i3);

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