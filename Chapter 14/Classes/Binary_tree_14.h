#pragma once
#include "../../Graph.h"
#include "Arrow.h"

namespace Graph_lib
{
	enum Connector_type {
		standard,
		arrow_up,
		arrow_down,
	};

	class Binary_tree_14 :
		public Shape
	{
	public:
		Binary_tree_14(Point xy, int levels, Connector_type con);
		virtual void draw_lines() const;
		void move(int dx, int dy);
		int levels() const { return lvl; }
		void set_node_label(string n, string lbl);

	protected:
		Vector_ref<Shape> edges;
		Vector_ref<Text> labels;

	private:
		int lvl;
		const int arrow_head_length = 5;
		const int arrow_head_setback = 12;
		const int dltX = 35;	// lateral distance between nodes - delta x
		const int dltY = 100;	// vertical distance between levels - delta y
		const int node_radius = 12;
	};
}

