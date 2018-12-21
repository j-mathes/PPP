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

	Graph_lib::Rectangle r{ Point{200,450},170,50 };
	//chapter12.cpp
	Graph_lib::Text t1{ Point{202,445},"chapter12.cpp" };
	//#include 'Graph.h'
	Graph_lib::Text t2{ Point{202,462},"#include 'Graph.h'" };
	//#include 'Simple_window.h'
	Graph_lib::Text t3{ Point{202,475},"#include 'Simple_window.h'" };
	//int main() {...}
	Graph_lib::Text t4{ Point{202,488},"int main() {...}" };
	//Line 1
	Graph_lib::Line l1{ Point{300,450},Point{420,400} };
	//Simple_windows.h rectangle
	Graph_lib::Polygon r2;
	r2.add(Point{ 350,400 });
	r2.add(Point{ 350,350 });
	r2.add(Point{ 520,350 });
	r2.add(Point{ 520,400 });
	//Simple_window.h
	Graph_lib::Text t5{ Point{350,342},"Simple_window.h" };
	// //Window interface:
	Graph_lib::Text t6{ Point{354,363},"//Window interface:" };
	// class Simple_window {...};
	Graph_lib::Text t7{ Point{354,375},"class Simple_window {...};" };
	// ...
	Graph_lib::Text t8{ Point{354,383},"..." };
	win.attach(r);
	win.attach(t1);
	win.attach(t2);
	win.attach(t3);
	win.attach(t4);
	win.attach(l1);
	win.attach(r2);
	win.attach(t5);
	win.attach(t6);
	win.attach(t7);
	win.attach(t8);

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