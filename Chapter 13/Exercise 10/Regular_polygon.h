#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Regular_polygon :
		public Shape
	{
	public:
		Regular_polygon(Point p, int rr, int ss)
			:r{ rr }, s{ss}
		{
			if (s <= 2) error("Bad polygon: requires more than 3 sides");
			add(Point{ p.x - r, p.y - r });
		}
		void draw_lines() const;
		Point center() const { return { point(0).x + r, point(0).y + r }; }
		void set_radius(int rr) { r = rr; }
		int radius() const { return r; }

	private:
		int r;
		int s;
		Point polygon_point(int d) const;
	};
}

