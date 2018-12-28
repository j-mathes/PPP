//----------------------------------------------------------------------------
// File:	Exercise 07.cpp
// Date:	2018-12-27
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 07
//----------------------------------------------------------------------------
// Description: RGB Color Chart
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

	const int tlX = 50;
	const int tlY = 50;
	const int winX = 1000;
	const int winY = 1000;

	Point tl{ tlX,tlY };
	Vector_ref<Graph_lib::Rectangle> colorChart;

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 07" };
	for (int r=0; r<256; r+=8)
	{
		win.set_label("Chapter 13, Exercise 07, R=" + to_string(r));
		for (int g=0; g<256; g+=8)
		{
			for (int b=0; b<256; b+=8)
			{
				colorChart.push_back(new Graph_lib::Rectangle{ Point{g*3, b*3},32,32 });
				colorChart[colorChart.size() - 1].set_fill_color(fl_rgb_color(r,g,b));
				colorChart[colorChart.size() - 1].set_color(Color::invisible);
				win.attach(colorChart[colorChart.size() - 1]);
			}
		}
		win.wait_for_button();
	}

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