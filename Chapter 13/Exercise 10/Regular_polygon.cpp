#include "Regular_polygon.h"

void Graph_lib::Regular_polygon::draw_lines() const
{
	Polygon poly;
	for (int i=0; i<s; ++i)
	{
		poly.add(polygon_point(i * 360 / s));
	}
	poly.draw_lines();
}

Graph_lib::Point Graph_lib::Regular_polygon::polygon_point(int d) const
{
	double radians = d * 3.14159265 / 180;
	Point result;
	result.x = static_cast<int>(center().x + radius() * cos(radians));
	result.y = static_cast<int>(center().y + radius() * sin(radians));
	return result;
}