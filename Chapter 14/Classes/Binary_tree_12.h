#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Binary_tree_12 :
		public Shape
	{
	public:
		Binary_tree_12(Point xy, int levels);
		virtual void draw_lines() const;
		void move(int dx, int dy);

	protected:
		Vector_ref<Shape> edges;

	private:
		int lvl;
		const int dltX = 35;	// lateral distance between nodes - delta x
		const int dltY = 100;	// vertical distance between levels - delta y
		const int node_radius = 12;
	};
}

