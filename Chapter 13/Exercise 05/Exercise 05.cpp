//----------------------------------------------------------------------------
// File:	Exercise 05.cpp
// Date:	2018-12-26
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 13
// Project:	Exercise 05
//----------------------------------------------------------------------------
// Description: Add connection points for Circle and Ellipse
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../Simple_window.h"
#include "ConnectionPoint.h"

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

	Simple_window win{ tl,winX,winY,"Chapter 13, Exercise 04" };
	Graph_lib::Circle c(Point{ 200,200 }, 150);
	c.set_color(Color::black);
	win.attach(c);

	Graph_lib::Ellipse el(Point{ 500,500 }, 200, 100);
	el.set_color(Color::black);
	win.attach(el);

	//Point c_north = n(c);
	Point c_north = nw(c);
	Mark m1(c_north, 'X');
	m1.set_color(Color::red);
	win.attach(m1);

	//Point c_south = s(c);
	Point c_south = ne(c);
	Mark m2(c_south, 'X');
	m2.set_color(Color::green);
	win.attach(m2);

	//Point c_east = e(c);
	Point c_east = sw(c);
	Mark m3(c_east, 'X');
	m3.set_color(Color::blue);
	win.attach(m3);

	//Point c_west = w(c);
	Point c_west = se(c);
	Mark m4(c_west, 'X');
	m4.set_color(Color::black);
	win.attach(m4);

	Point c_center = center(c);
	Mark m5(c_center, 'X');
	m5.set_color(Color::dark_yellow);
	win.attach(m5);

	//------------------------------------------------

	//Point e_north = n(el);
	Point e_north = nw(el);
	Mark m6(e_north, 'X');
	m6.set_color(Color::red);
	win.attach(m6);

	//Point e_south = s(el);
	Point e_south = ne(el);
	Mark m7(e_south, 'X');
	m7.set_color(Color::green);
	win.attach(m7);

	//Point e_east = e(el);
	Point e_east = sw(el);
	Mark m8(e_east, 'X');
	m8.set_color(Color::blue);
	win.attach(m8);

	//Point e_west = w(el);
	Point e_west = se(el);
	Mark m9(e_west, 'X');
	m9.set_color(Color::black);
	win.attach(m9);

	Point e_center = center(el);
	Mark m10(e_center, 'X');
	m10.set_color(Color::dark_yellow);
	win.attach(m10);
	
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