#include "Group.h"

void Graph_lib::Group::draw() const
{
	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i].draw();
	}
}

void Graph_lib::Group::move(int dx, int dy)
{
	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i].move(dx,dy);
	}
}

void Graph_lib::Group::set_color(Color col)
{
	Shape::set_color(col);
	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i].set_color(col);
	}
}

void Graph_lib::Group::set_style(Line_style sty)
{
	Shape::set_style(sty);
	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i].set_style(sty);
	}
}

void Graph_lib::Group::set_fill_color(Color col)
{
	Shape::set_fill_color(col);
	for (int i = 0; i < shapes.size(); ++i)
	{
		shapes[i].set_fill_color(col);
	}
}

