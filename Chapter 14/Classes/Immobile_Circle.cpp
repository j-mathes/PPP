#include "Immobile_Circle.h"

Graph_lib::Immobile_Circle::Immobile_Circle(Point center, int radius)
	:Circle(center, radius)
{
}

void Graph_lib::Immobile_Circle::draw_lines() const
{
	Graph_lib::Circle::draw_lines();
}

void Graph_lib::Immobile_Circle::move(int dx, int dy)
{
	cout << "Move is prohibited" << endl;
}
