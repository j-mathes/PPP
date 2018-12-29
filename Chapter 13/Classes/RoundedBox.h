#pragma once
#include "../../Graph.h"
#include "Arc.h"

namespace Graph_lib {

	class RoundedBox :
		public Graph_lib::Shape
	{
	public:
		RoundedBox(Graph_lib::Point pp, int ww, int hh, int rr)
			:tl{ pp }, w { ww }, h{ hh }, r{ rr }
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
			bl.x = tl.x;
			bl.y = tl.y + h;
			br.x = tl.x + w;
			br.y = tl.y + h;
			tr.x = tl.x + w;
			tr.y = tl.y;
			add_points();
		}

		RoundedBox(Point x, Point y, int rr) 
			:tl{ x }, br{ y }, w{ y.x - x.x }, h{ y.y - x.y }, r{ rr }
		{
			if (h <= 0 || w <= 0) error("Bad rectangle: first point is not top left");
			bl.x = tl.x;
			bl.y = tl.y + h;
			tr.x = tl.x + w;
			tr.y = tl.y;
			add_points();
		}

		void draw_lines() const;
		int height() const { return h; }
		int width() const { return w; }
		int corner_radius() const { return r; }
		void add_points();

	private:
		Point tl;
		Point bl;
		Point br;
		Point tr;
		int w;
		int h;
		int r;
	};
}