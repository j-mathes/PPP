//----------------------------------------------------------------------------
// File:	Exercise 07.cpp
// Date:	2018-12-19
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 07
//----------------------------------------------------------------------------
// Description: Draw a house
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

	Simple_window win{ tl,winX,winY,"Exercise 07" };

	// House shape

	Graph_lib::Rectangle chimney{ Point{150,50}, 50, 150 };
	chimney.set_fill_color(Color::dark_red);
	win.attach(chimney);

	Graph_lib::Polygon house;
	house.add(Point{ 100,200 });
	house.add(Point{ 100,500 });
	house.add(Point{ 400,500 });
	house.add(Point{ 400,200 });
	house.add(Point{ 250,50 });
	house.set_color(Color::black);
	house.set_fill_color(Color::dark_green);
	win.attach(house);

	Graph_lib::Rectangle door{ Point{150,340}, 75, 150 };
	door.set_fill_color(Color::dark_blue);
	win.attach(door);

	Graph_lib::Rectangle window1{ Point{150,260}, 75, 50 };
	window1.set_fill_color(Color::cyan);
	win.attach(window1);

	Graph_lib::Rectangle window2{ Point{250,340}, 120, 100 };
	window2.set_fill_color(Color::cyan);
	win.attach(window2);

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