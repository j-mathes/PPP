#include "Arc.h"

void Graph_lib::Arc::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, startAng, endAng);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		//fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, r + r, r + r, startAng, endAng);
	}
}
