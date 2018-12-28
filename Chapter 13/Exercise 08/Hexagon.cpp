#include "Hexagon.h"

void Graph_lib::Hexagon::draw_lines() const
{
	Polygon hex_poly;
	for (int i=0; i<6; ++i)
	{
		hex_poly.add(hexagon_point(i * 60));
	}
	hex_poly.draw_lines();
}

Graph_lib::Point Graph_lib::Hexagon::hexagon_point(int d) const
{
	double radians = d * 3.14159265 / 180;
	Point result;
	result.x = static_cast<int>(center().x + radius() * cos(radians));
	result.y = static_cast<int>(center().y + radius() * sin(radians));
	return result;
}
