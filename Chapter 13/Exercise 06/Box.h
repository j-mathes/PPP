#pragma once
#include "../../Graph.h"
namespace Graph_lib
{
	class Box :
		public Rectangle
	{
	public:
		Box(Point pp, int ww, int hh, string label = "")
			:Rectangle(pp, ww, hh), t{pp, label}
		{

		}

		void draw_lines() const;
	
	private:
		Text t;
	};
}

