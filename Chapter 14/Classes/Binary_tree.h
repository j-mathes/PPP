#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Binary_tree :
		public Shape
	{
	public:
		Binary_tree(int ll = 0)
			:l{ ll }
		{
		}
	
		void draw() const;

	private:
		int l;
	};
}

