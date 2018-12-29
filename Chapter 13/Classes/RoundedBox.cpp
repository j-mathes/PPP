#include "RoundedBox.h"

void Graph_lib::RoundedBox::draw_lines() const
{
	for (int i = 1; i < number_of_points(); i += 2)
		fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);

	// draw corners
	fl_arc(tl.x, tl.y, r + r, r + r, 90, 180);						// top left
	fl_arc(bl.x, bl.y - (2 * r), r + r, r + r, 180, 270);			// bottom left
	fl_arc(br.x - (2 * r), br.y - (2 * r), r + r, r + r, 270, 360);	// bottom right
	fl_arc(tr.x - (2 * r), tr.y, r + r, r + r, 360, 90);			// top right
}

void Graph_lib::RoundedBox::add_points()
{
	add(Point{ tl.x + r, tl.y });
	add(Point{ tl.x + w - r, tl.y });
	add(Point{ tl.x + r, tl.y + h });
	add(Point{ tl.x + w - r, tl.y + h });
	add(Point{ tl.x, tl.y + r });
	add(Point{ tl.x, tl.y + h - r });
	add(Point{ tl.x + w, tl.y + r });
	add(Point{ tl.x + w, tl.y + h - r });
}
