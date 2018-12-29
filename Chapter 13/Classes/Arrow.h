#pragma once
#include "../../Graph.h"
#include "Vec.h"

namespace Graph_lib {
	class Arrow :
		public Graph_lib::Shape
	{
	public:
		Arrow(Graph_lib::Point ps, Graph_lib::Point pe, int ahl)
			:arrowHead_length{ ahl }, p1{ps}, p2{pe}
		{
			add(ps);
			add(pe);
		}

		void draw_lines() const;

	private:
		int arrowHead_length;
		Point p1;
		Point p2;
		void arrowhead(Vec a, Vec b, Vec& v1, Vec& v2) const;
	};

}