#pragma once
#include "../../Graph.h"

namespace Graph_lib
{
	class Immobile_Circle :
		public Circle
	{
	public:
		Immobile_Circle(Point center, int radius);
		void draw_lines() const;
		void move(int dx, int dy);
	};
}