#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Group :
		public Shape
	{
	public:
		void add_shape(Shape& s) { shapes.push_back(s); }

		void draw() const;
		void move(int dx, int dy);

		void set_color(Color col);
		void set_style(Line_style sty);
		void set_fill_color(Color col);

	private:
		Vector_ref<Shape> shapes;
		Shape::number_of_points;
		Shape::point;
		Shape::add;
		Shape::set_point;
	};
}

