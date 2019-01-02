#include "Striped_Closed_Polyline.h"

Graph_lib::Striped_Closed_Polyline::Striped_Closed_Polyline()
{
}

void Graph_lib::Striped_Closed_Polyline::draw_lines() const
{
	Closed_polyline::draw_lines();

	if (fill_color().visibility())
	{
		int min_x = point(0).x; // top left-most point's x
		int min_y = point(0).y; // top left-most point's y
		int max_x = point(0).x; // right-most point's x
		int max_y = point(0).y; // bottom point's y
		vector<Point> lines; // to hold lines
		for (int i = 1; i < number_of_points(); ++i) {
			if (point(i).x < min_x) min_x = point(i).x;
			if (point(i).y < min_x) min_y = point(i).y;
			if (point(i).x > max_x) max_x = point(i).x;
			if (point(i).y > max_y) max_y = point(i).y;
		}
		// Search for intersections of polyline and horizontal lines
		for (int y = min_y; y < max_y; y += 3) {
			Point intersect;
			for (int i = 1; i < number_of_points(); ++i) {
				if (line_segment_intersection(Point{ min_x,y }, Point{ max_x,y }, point(i - 1), point(i), intersect)) {
					lines.push_back(intersect); // find an intersection of polyline and horizontal lines
				}
			}
	
			if (line_segment_intersection(Point{ min_x,y }, Point{ max_x,y }, point(number_of_points() - 1), point(0), intersect)) {
				lines.push_back(intersect); // last line of polyline (starting in the last point and ending in the first one)
			}
		}
	
		for (size_t i = 1; i < lines.size(); i += 2) {
			Line l{ lines[i],lines[i - 1] }; // draw lines
			l.draw();
		}
	}
}

