#include "Octagon.h"

void Graph_lib::Octagon::draw_lines() const
{
	Polygon oct_poly;
	for (int i = 0; i < 8; ++i)
	{
		oct_poly.add(octagon_point(i * 45));
	}
	oct_poly.draw_lines();
}

Graph_lib::Point Graph_lib::Octagon::octagon_point(int d) const
{
	double radians = d * 3.14159265 / 180;
	Point result;
	result.x = static_cast<int>(center().x + radius() * cos(radians));
	result.y = static_cast<int>(center().y + radius() * sin(radians));
	return result;
}

