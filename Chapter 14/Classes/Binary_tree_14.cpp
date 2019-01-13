#include "Binary_tree_14.h"

Graph_lib::Binary_tree_14::Binary_tree_14(Point xy, int levels, Connector_type con)
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
	switch (con)
	{
	case Graph_lib::arrow_down:
	{
		for (int i = 0; i < number_of_points() / 2; ++i)
		{
			edges.push_back(new Arrow(point(i), Point(point(2 * i + 1).x, point(2 * i + 1).y - arrow_head_setback), arrow_head_length));
			edges[edges.size() - 1].set_color(Color::black);
			edges.push_back(new Arrow(point(i), Point(point(2 * i + 2).x, point(2 * i + 2).y - arrow_head_setback), arrow_head_length));
			edges[edges.size() - 1].set_color(Color::black);
		}
		break;
	}
	case Graph_lib::arrow_up:
	{
		for (int i = 0; i < number_of_points() / 2; ++i)
		{
			edges.push_back(new Arrow(point(2 * i + 1), Point(point(i).x, point(i).y + arrow_head_setback), arrow_head_length));
			edges[edges.size() - 1].set_color(Color::black);
			edges.push_back(new Arrow(point(2 * i + 2), Point(point(i).x, point(i).y + arrow_head_setback), arrow_head_length));
			edges[edges.size() - 1].set_color(Color::black);
		}
		break;
	}
	case Graph_lib::standard:
	default:
	{
		for (int i = 0; i < number_of_points() / 2; ++i)
		{
			edges.push_back(new Line(point(i), point(2 * i + 1)));
			edges[edges.size() - 1].set_color(Color::black);
			edges.push_back(new Line(point(i), point(2 * i + 2)));
			edges[edges.size() - 1].set_color(Color::black);
		}
		break;
	}
	}

	// labels
	for (int  i = 0; i < number_of_points(); ++i)
	{
		labels.push_back(new Text(Point(point(i).x + node_radius + 2, point(i).y + node_radius / 2),""));
	}
}

void Graph_lib::Binary_tree_14::draw_lines() const
{
	if (color().visibility()) {
		for (int i = 0; i < edges.size(); ++i)
		{
			edges[i].draw();
		}

		for (int i = 0; i < number_of_points(); ++i)
		{
			labels[i].draw();
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

void Graph_lib::Binary_tree_14::move(int dx, int dy)
{
	Shape::move(dx, dy);
	for (int i = 0; i < edges.size(); ++i)
	{
		edges[i].move(dx, dy);
	}
}

void Graph_lib::Binary_tree_14::set_node_label(string n, string lbl)
{
	if (n.size() < 1 || n.size() > lvl) error("set_node_label: illegal node string ", n);
	istringstream iss(n);
	char ch;
	iss.get(ch);    // look at first character
	if (n.size() == 1) {
		switch (ch) {
		case 'l':
		case 'r':
			labels[0].set_label(lbl);
			labels[0].set_color(Color::black);
			return;
		default:
			error("set_node_label: illegal character in node string: ", string(1, ch));
		}
	}
	int n_idx = 0;  // node index in point list
	while (iss.get(ch)) {
		switch (ch) {
		case 'l':
			n_idx = 2 * n_idx + 1;
			break;
		case 'r':
			n_idx = 2 * n_idx + 2;
			break;
		default:
			error("set_node_label: illegal character in node string: ", string(1, ch));
		}
	}
	labels[n_idx].set_label(lbl);
	labels[n_idx].set_color(Color::black);
}
