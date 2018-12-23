//----------------------------------------------------------------------------
// File:	Drill.cpp
// Date:	2018-12-22
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Drill
//----------------------------------------------------------------------------
// Description: Grid with pictures
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
	const int winX = 800;
	const int winY = 1000;

	Point tl{ tlX,tlY };

	Simple_window win{ tl,winX,winY,"Chapter 13, Drill" };

	Vector_ref <Graph_lib::Rectangle> grid;
	for (int x = 0; x <= 7; ++x)
	{
		for (int y = 0; y <= 7; ++y)
		{
			grid.push_back(new Graph_lib::Rectangle{ Point{(x * 100), (y * 100)}, 100, 100 });
			grid[grid.size() - 1].set_color(Color::black);
			win.attach(grid[grid.size() - 1]);
		}
	}

	for (int i=0; i<grid.size();)
	{
		grid[i].set_fill_color(Color::red);
		i = i + 9;
	}

	Graph_lib::Image img1{ Point{0,200}, "image.jpg" };
	img1.set_mask(Point{ 100,100 }, 200, 200);
	win.attach(img1);

	Graph_lib::Image img2{ Point{100,500}, "image.jpg" };
	img2.set_mask(Point{ 200,100 }, 200, 200);
	win.attach(img2);

	Graph_lib::Image img3{ Point {600,300}, "image.jpg" };
	img3.set_mask(Point{ 100,200 }, 200, 200);
	win.attach(img3);

	Graph_lib::Image img4{ Point{0,0}, "image.jpg" };
	img4.set_mask(Point{ 400,400 }, 100, 100);
	win.attach(img4);

	std::srand(time(NULL));
	while (true)
	{
		int randX = rand() % 8;
		int randY = rand() % 8;
		int dx = 100 * randX - img4.point(0).x;
		int dy = 100 * randY - img4.point(0).y;
		img4.move(dx, dy);
		win.wait_for_button();
	}
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