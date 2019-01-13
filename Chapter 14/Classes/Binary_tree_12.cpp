#include "Binary_tree_12.h"

Graph_lib::Binary_tree_12::Binary_tree_12(Point xy, int levels)
	: lvl(levels)
{
	// Determine nodes
	if (levels < 0) error("Binary_tree_12: levels must be at least zero");

	if (levels == 0) return;

	// if levels == 1, only the root node is added
	add(xy);

	for (int i = 2; i <= levels; ++i)
	{
		for (int j = 0; j < pow(2,i-1); ++j)
		{
			int x = xy.x - static_cast<int>(((pow(2, i - 1) - 1) / 2 - j) * pow(2, levels - i)*dltX);
			int y = xy.y + (i - 1)*dltY;
			add(Point(x, y));
		}
	}

	// Connect nodes with lines
	for (int i = 0; i < number_of_points()/2; ++i)
	{
		edges.push_back(new Line(point(i), point(2 * i + 1)));
		edges[edges.size() - 1].set_color(Color::black);
		edges.push_back(new Line(point(i), point(2 * i + 2)));
		edges[edges.size() - 1].set_color(Color::black);
	}
}

void Graph_lib::Binary_tree_12::draw_lines() const
{
	if (color().visibility()) {
		for (int i = 0; i < edges.size(); ++i)
		{
			edges[i].draw();
		}

		fl_color(fl_rgb_color(192, 192, 192));
		for (int i = 0; i < number_of_points(); ++i)
			fl_pie(point(i).x - node_radius, point(i).y - node_radius, node_radius + node_radius - 1, node_radius + node_radius - 1, 0, 360);
		fl_color(color().as_int());	// reset color
		fl_color(0, 0, 0);
		for (int i = 0; i < number_of_points(); ++i)
			fl_arc(point(i).x - node_radius, point(i).y - node_radius, node_radius + node_radius, node_radius + node_radius, 0, 360);
	}
}

void Graph_lib::Binary_tree_12::move(int dx, int dy)
{
	Shape::move(dx, dy);
	for (int i = 0; i < edges.size(); ++i)
	{
		edges[i].move(dx, dy);
	}
}
