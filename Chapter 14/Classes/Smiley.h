#pragma once
#include "../../Graph.h"
#include "Arc.h"
namespace Graph_lib
{
	class Smiley :
		public Circle
	{
	public:
		Smiley(Point center, int radius);
		void draw_lines() const;
	};
}

