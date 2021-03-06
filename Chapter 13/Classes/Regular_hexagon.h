#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Regular_hexagon :
		public Shape
	{
	public:
		Regular_hexagon(Point p, int rr)
			:r{ rr }
		{
			add(Point{ p.x - r, p.y - r });
		}
	
		void draw_lines() const;
		Point center() const { return { point(0).x + r, point(0).y + r }; }
		void set_radius(int rr) { r = rr; }
		int radius() const { return r; }

	private:
		int r;
		Point hexagon_point(int d) const;
	};
}

