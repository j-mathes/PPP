#include "Striped_Rectangle.h"

Graph_lib::Striped_Rectangle::Striped_Rectangle(Point xy, int ww, int hh)
	:Rectangle(xy, ww, hh)
{
}

Graph_lib::Striped_Rectangle::Striped_Rectangle(Point x, Point y)
	:Rectangle(x, y)
{
}

void Graph_lib::Striped_Rectangle::draw_lines() const
{
	if (fill_color().visibility()) {			// fill
		fl_color(fill_color().as_int());
		//fl_rectf(point(0).x, point(0).y, width(), height());
		for (int i = 0; i < height(); i+= 3)
		{
			fl_line(point(0).x, point(0).y + i, point(0).x + width() - 1, point(0).y + i);
		}
		fl_color(color().as_int());				// reset color
	}

	if (color().visibility()) {					// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x, point(0).y, width(), height());
	}
}