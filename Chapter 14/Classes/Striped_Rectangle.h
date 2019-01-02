#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Striped_Rectangle :
		public Rectangle
	{
	public:
		Striped_Rectangle(Point xy, int ww, int hh);
		Striped_Rectangle(Point x, Point y);
		void draw_lines() const;
	};
}