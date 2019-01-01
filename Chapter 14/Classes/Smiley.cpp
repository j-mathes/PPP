#include "Smiley.h"

Graph_lib::Smiley::Smiley(Point center, int radius)
	:Circle(center,radius)
{
}

void Graph_lib::Smiley::draw_lines() const 
{
	Graph_lib::Circle::draw_lines();
	Graph_lib::Circle eye1{ Point {center().x - radius() / 2,center().y - radius() / 2},radius() / 4 };
	eye1.draw_lines();
	Graph_lib::Circle eye2{ Point {center().x + radius() / 2,center().y - radius() / 2},radius() / 4 };
	eye2.draw_lines();
	Graph_lib::Arc smile( center() , static_cast<int>(radius() * 0.5), 180, 360);
	smile.draw_lines();
}