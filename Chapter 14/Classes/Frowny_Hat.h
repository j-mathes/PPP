#pragma once
#include "Frowny.h"
namespace Graph_lib
{
	class Frowny_Hat :
		public Frowny
	{
	public:
		Frowny_Hat(Point center, int radius);
		void draw_lines() const;
	};
}

