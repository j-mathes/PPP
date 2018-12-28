#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	Point point_on_circle(Circle&, int);

	Point n(Graph_lib::Rectangle&);		// Returns center north connection point
	Point n(Graph_lib::Circle&);		// Returns center north connection point
	Point n(Graph_lib::Ellipse&);		// Returns center north connection point

	Point s(Graph_lib::Rectangle&);		// Returns center north connection point
	Point s(Graph_lib::Circle&);		// Returns center north connection point
	Point s(Graph_lib::Ellipse&);		// Returns center north connection point

	Point e(Graph_lib::Rectangle&);		// Returns center north connection point
	Point e(Graph_lib::Circle&);		// Returns center north connection point
	Point e(Graph_lib::Ellipse&);		// Returns center north connection point

	Point w(Graph_lib::Rectangle&);		// Returns center north connection point
	Point w(Graph_lib::Circle&);		// Returns center north connection point
	Point w(Graph_lib::Ellipse&);		// Returns center north connection point

	Point center(Graph_lib::Rectangle&);	// Returns center north connection point
	Point center(Graph_lib::Circle&);		// Returns center north connection point
	Point center(Graph_lib::Ellipse&);		// Returns center north connection point

	Point ne(Graph_lib::Rectangle&);		// Returns center north connection point
	Point ne(Graph_lib::Circle&);		// Returns center north connection point
	Point ne(Graph_lib::Ellipse&);		// Returns center north connection point

	Point nw(Graph_lib::Rectangle&);		// Returns center north connection point
	Point nw(Graph_lib::Circle&);		// Returns center north connection point
	Point nw(Graph_lib::Ellipse&);		// Returns center north connection point

	Point se(Graph_lib::Rectangle&);		// Returns center north connection point
	Point se(Graph_lib::Circle&);		// Returns center north connection point
	Point se(Graph_lib::Ellipse&);		// Returns center north connection point

	Point sw(Graph_lib::Rectangle&);		// Returns center north connection point
	Point sw(Graph_lib::Circle&);		// Returns center north connection point
	Point sw(Graph_lib::Ellipse&);		// Returns center north connection point
}

