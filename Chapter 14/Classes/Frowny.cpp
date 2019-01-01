#include "Frowny.h"

Graph_lib::Frowny::Frowny(Point center, int radius)
	:Circle(center, radius)
{
}

void Graph_lib::Frowny::draw_lines() const
{
	Graph_lib::Circle::draw_lines();
	Graph_lib::Circle eye1{ Point {center().x - radius() / 2,center().y - radius() / 2},radius() / 4 };
	eye1.draw_lines();
	Graph_lib::Circle eye2{ Point {center().x + radius() / 2,center().y - radius() / 2},radius() / 4 };
	eye2.draw_lines();
	Graph_lib::Arc frown(Point(center().x, center().y + (radius() / 2)), static_cast<int>(radius() * 0.5), 360, 180);
	frown.draw_lines();
}

