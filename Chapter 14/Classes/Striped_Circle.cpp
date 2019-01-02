#include "Striped_Circle.h"

Graph_lib::Striped_Circle::Striped_Circle(Point center, int radius)
	:Circle(center, radius)
{
}

void Graph_lib::Striped_Circle::draw_lines() const
{
	if (fill_color().visibility()) {			// fill
		fl_color(fill_color().as_int());
		//fl_pie(point(0).x, point(0).y, radius() + radius() - 1, radius() + radius() - 1, 0, 360);
		for (int i = center().y - radius(); i < center().y + radius(); i+= 3)
		{
			int dy = center().y - i;
			int dx = static_cast<int>(round(sqrt(radius()*radius() - dy * dy)) - 1);
			fl_line(center().x - dx, i, center().x + dx, i);
		}
		fl_color(color().as_int());				// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, radius() + radius(), radius() + radius(), 0, 360);
	}
}
