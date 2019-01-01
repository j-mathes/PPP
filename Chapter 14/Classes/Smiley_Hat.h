#pragma once
#include "Smiley.h"
namespace Graph_lib
{
	class Smiley_Hat :
		public Smiley
	{
	public:
		Smiley_Hat(Point center, int radius);
		void draw_lines() const;
	};
}

