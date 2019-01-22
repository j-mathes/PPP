//----------------------------------------------------------------------------
// File:	Drill A.cpp
// Date:	2019-01-22
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 15
// Project:	Drill A
//----------------------------------------------------------------------------
// Description: Function Graphing Drill
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Window.h"

using namespace Graph_lib;
// Constant Expressions

constexpr int tlX = 50;				// Origin of window on desktop
constexpr int tlY = 50;

constexpr int xmax = 600;			// window size
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;	// position of (0,0) is center of window
constexpr int y_orig = ymax / 2;

constexpr int r_min = -10;			// range [–10:11]
constexpr int r_max = 11;

constexpr int n_points = 400;		// number of points used in range

constexpr int x_scale = 20;			// scaling factors
constexpr int y_scale = 20;

constexpr int x_offset = 100;		// distance from left-hand side of window to x axis
constexpr int y_offset = 100;		// distance from bottom of window to x axis

constexpr int x_space = 40;			// space beyond axis
constexpr int y_space = 40;

constexpr int x_axis_length = 400;
constexpr int y_axis_length = 400;

//constexpr int x_axis_length = xmax - x_offset - x_space;
//constexpr int y_axis_length = ymax - y_offset - y_space;

constexpr int x_axis_notches = x_axis_length / 20;
constexpr int y_axis_notches = y_axis_length / 20;

// Functions
double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	Point tl{ tlX,tlY };
	Point origin{ 300,300 };

	Graph_lib::Window win{ tl,xmax,ymax,"Chapter 15, Drill A, Function Graphs" };

	Axis x{ Axis::x, Point{x_offset,ymax / 2},x_axis_length,x_axis_notches,"1 == 20" };
	Axis y{ Axis::y, Point{xmax / 2,y_offset + y_axis_length},y_axis_length,y_axis_notches,"1 == 20" };

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	Function f1(one, r_min, r_max, origin, 400, x_scale, y_scale);
	f1.set_color(Color::blue);
	win.attach(f1);

	Function f2(slope, r_min, r_max, origin, 400, x_scale, y_scale);
	f2.set_color(Color::dark_yellow);
	win.attach(f2);

	Text f2_label(Point{ f2.point(0).x, f2.point(0).y - 10 }, "x/2");
	f2_label.set_color(Color::dark_yellow);
	win.attach(f2_label);

	Function f3(square, r_min, r_max, origin, 400, x_scale, y_scale);
	f3.set_color(Color::green);
	win.attach(f3);

	Function f4([](double x) {return cos(x); }, r_min, r_max, origin, 400, x_scale, y_scale);
	f4.set_color(Color::cyan);
	win.attach(f4);

	Function f5(sloping_cos, r_min, r_max, origin, 400, x_scale, y_scale);
	f5.set_color(Color::magenta);
	win.attach(f5);

	gui_main();
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