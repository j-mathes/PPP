#pragma once
#include "RoundedBox.h"
#include "Box.h"

namespace Graph_lib
{
	class Pseudo_window :
		public RoundedBox
	{
	public:
		Pseudo_window(Point pp, int ww, int hh, string str);
		void draw_lines() const;

	private:
		Point p;
		int w;
		int h;
		Text lab;
		Box inner_border;
		Box minimize;
		Box maximize;
		Box close_window;
	};
	
}
