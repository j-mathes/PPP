#pragma once
#include "../../Graph.h"
#include "Arc.h"
namespace Graph_lib
{
	class Frowny :
		public Circle
	{
	public:
		Frowny(Point center, int radius);
		void draw_lines() const;
	};
}

