//----------------------------------------------------------------------------
// File:	Drill 03.cpp
// Date:	2018-12-17
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 12
// Project:	Drill 03
//----------------------------------------------------------------------------
// Description: Examples with modifications
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

	Point tl{ 200, 200 };							// Top left corner of window
	Simple_window win{ tl, 800, 500, "My Windowz" };//make a simple window

	win.wait_for_button();							// give control to the display engine

	//----------------------------------------------------------------------------
	// Axis
	//----------------------------------------------------------------------------
	Axis xa{ Axis::x, Point{20,300}, 280, 5, "x axis" };	// make an Axis
															// an Axis is a kind of Shape
															// Axis::x means horizontal
															// starting at (20,300)
															// 280 pixels long
															// 10 notches
															// label the axis "x axis"
	win.attach(xa);											// attach xa to the window, win
	win.set_label("Canvas #2");								// relabel the window
	win.wait_for_button();									// display!

	Axis ya{ Axis::y, Point{20,300}, 280, 5, "y axis" };
	ya.set_color(Color::green);								// choose a color
	ya.label.set_color(Color::red);							// choose a color for the text
	win.attach(ya);
	win.set_label("Canvas #3");
	win.wait_for_button();									// display!

	//----------------------------------------------------------------------------
	// Graphing a function
	//----------------------------------------------------------------------------
	Function sine{ sin,0,100,Point{20,150},1000,30,50 };	// sine curve
															// plot sin() in the range [0:100) with (0,0) at (20,150)
															// using 1000 points; scale x values *50, scale y values *50

	win.attach(sine);
	win.set_label("Canvas #4");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// Polygons
	//----------------------------------------------------------------------------
	sine.set_color(Color::blue);							// we changed our mind about sine’s color

	Graph_lib::Polygon poly;								// a polygon; a Polygon is a kind of Shape
	poly.add(Point{ 300,250 });								// three points make a triangle
	poly.add(Point{ 350,100 });
	poly.add(Point{ 400,200 });

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// Rectangles
	//----------------------------------------------------------------------------
	Graph_lib::Rectangle r{ Point{200,200}, 150, 50 };		// top left corner, width, height
	win.attach(r);
	win.set_label("Canvas #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 200,100 });
	poly_rect.add(Point{ 100,100 });
	win.attach(poly_rect);
	win.set_label("Canvas #6.1");
	win.wait_for_button();

	poly_rect.add(Point{ 50,75 });
	win.set_label("Canvas #6.2");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// Fill
	//----------------------------------------------------------------------------
	r.set_fill_color(Color::dark_yellow);					// color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 3));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// Text
	//----------------------------------------------------------------------------
	Text t{ Point{150,150}, "Yo Yo, graphical world!" };
	win.attach(t);
	win.set_label("Canvas #8");
	win.wait_for_button();

	t.set_font(Font::helvetica_bold_italic);
	t.set_font_size(35);
	win.set_label("Canvas #9");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// Images
	//----------------------------------------------------------------------------
	Image ii{ Point{100,50},"image.jpg" };					// 400*212-pixel jpg
	win.attach(ii);
	win.set_label("Canvas #10");
	win.wait_for_button();

	ii.move(100, 230);
	win.set_label("Canvas #11");
	win.wait_for_button();

	//----------------------------------------------------------------------------
	// More
	//----------------------------------------------------------------------------
	Circle c{ Point{100,200},50 };
	Graph_lib::Ellipse e{ Point{100,200}, 75,15 };
	e.set_color(Color::dark_red);
	Mark m{ Point{100,200},'x' };

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes{ Point{100,20},oss.str() };

	Image cal{ Point{225,225},"snow_cpp.gif" };				// 320*240-pixel gif
	cal.set_mask(Point{ 40,40 }, 200, 150);						// display center part of image
	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
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