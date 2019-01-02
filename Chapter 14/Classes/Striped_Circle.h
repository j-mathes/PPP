#pragma once
#include "../../Graph.h"
#include "ConnectionPoint.h"
namespace Graph_lib
{
	class Striped_Circle :
		public Circle
	{
	public:
		Striped_Circle(Point center, int radius);
		void draw_lines() const;
	};
}

