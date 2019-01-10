//----------------------------------------------------------------------------
// File:	Exercise 09.cpp
// Date:	2019-01-09
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 09
//----------------------------------------------------------------------------
// Description: Group class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../Classes/Group.h"
#include "../Classes/Frowny_Hat.h"
#include "../Classes/Octagon.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 14, Exercise 09" };
	
	Group grp;
	Octagon o{ Point{200,200},90 };
	o.set_color(Color::red);
	win.attach(o);
	grp.add_shape(o);

	Frowny_Hat fr{ Point{500,100},45 };
	fr.set_color(Color::blue);
	win.attach(fr);
	grp.add_shape(fr);

	Graph_lib::Rectangle re(Point{100,600},120,207);
	re.set_color(Color::dark_green);
	re.set_fill_color(Color::dark_yellow);
	win.attach(re);
	grp.add_shape(re);

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