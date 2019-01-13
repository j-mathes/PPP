#include "Binary_tree_12_square.h"

void Graph_lib::Binary_tree_12_square::draw_lines() const
{
	if (color().visibility()) {
		for (int i = 0; i < edges.size(); ++i)
		{
			edges[i].draw();
		}

		fl_color(fl_rgb_color(192, 192, 192));
		for (int i = 0; i < number_of_points(); ++i)
			fl_rectf(point(i).x - node_dimensions, point(i).y - node_dimensions, 2 * node_dimensions, 2 * node_dimensions);
		fl_color(color().as_int());	// reset color
		fl_color(0, 0, 0);
		for (int i = 0; i < number_of_points(); ++i)
			fl_rect(point(i).x - node_dimensions, point(i).y - node_dimensions, 2 * node_dimensions, 2 * node_dimensions);
	}
}
