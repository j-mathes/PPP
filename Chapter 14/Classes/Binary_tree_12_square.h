#pragma once
#include "Binary_tree_12.h"
namespace Graph_lib
{
	class Binary_tree_12_square :
		public Binary_tree_12
	{
	public:
		Binary_tree_12_square(Point xy, int levels) :
			Binary_tree_12(xy, levels)
		{
		}

		void draw_lines() const;

	private:
		const int node_dimensions = 12;	// width and height of node box
	};
}
