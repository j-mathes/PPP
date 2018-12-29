#pragma once
#include "../../Graph.h"

namespace Graph_lib {
	class Arc :
		public Graph_lib::Shape
	{
	public:
		Arc(Graph_lib::Point p, int rr, double ss, double ee)
			:r{ rr }, startAng{ ss }, endAng{ ee }
		{
			add(Point{ p.x - r, p.y - r });
		}

		void draw_lines() const;
		Point center() const { return { point(0).x + r, point(0).y + r }; }

		void set_radius(int rr) { r = rr; }
		void set_start_angle(double startAngle) { startAng = startAngle; }
		void set_end_angle(double endAngle) { endAng = endAngle; }
		int radius() const { return r; }
		double start_angle() const { return startAng; }
		double end_angle() const { return endAng; }

	private:
		int r;
		double startAng;
		double endAng;
	};

}