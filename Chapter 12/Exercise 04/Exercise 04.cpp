//----------------------------------------------------------------------------
// File:	Exercise 04.cpp
// Date:	2018-12-18
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Exercise 04
//----------------------------------------------------------------------------
// Description: Tic Tac Toe Grid
//----------------------------------------------------------------------------

//#include "../../std_lib_facilities.h"
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
	Simple_window win{ tl, 600, 400, "Exercise 04" };

	Graph_lib::Rectangle ttt_Grid_1_1{ Point{100,100}, 75, 75 };
	ttt_Grid_1_1.set_fill_color(Color::white);
	win.attach(ttt_Grid_1_1);

	Graph_lib::Rectangle ttt_Grid_1_2{ Point{200,100}, 75, 75 };
	ttt_Grid_1_2.set_fill_color(Color::red);
	win.attach(ttt_Grid_1_2);

	Graph_lib::Rectangle ttt_Grid_1_3{ Point{300,100}, 75, 75 };
	ttt_Grid_1_3.set_fill_color(Color::white);
	win.attach(ttt_Grid_1_3);

	Graph_lib::Rectangle ttt_Grid_2_1{ Point{100,200}, 75, 75 };
	ttt_Grid_2_1.set_fill_color(Color::red);
	win.attach(ttt_Grid_2_1);

	Graph_lib::Rectangle ttt_Grid_2_2{ Point{200,200}, 75, 75 };
	ttt_Grid_2_2.set_fill_color(Color::white);
	win.attach(ttt_Grid_2_2);

	Graph_lib::Rectangle ttt_Grid_2_3{ Point{300,200}, 75, 75 };
	ttt_Grid_2_3.set_fill_color(Color::red);
	win.attach(ttt_Grid_2_3);

	Graph_lib::Rectangle ttt_Grid_3_1{ Point{100,300}, 75, 75 };
	ttt_Grid_3_1.set_fill_color(Color::white);
	win.attach(ttt_Grid_3_1);

	Graph_lib::Rectangle ttt_Grid_3_2{ Point{200,300}, 75, 75 };
	ttt_Grid_3_2.set_fill_color(Color::red);
	win.attach(ttt_Grid_3_2);

	Graph_lib::Rectangle ttt_Grid_3_3{ Point{300,300}, 75, 75 };
	ttt_Grid_3_3.set_fill_color(Color::white);
	win.attach(ttt_Grid_3_3);

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