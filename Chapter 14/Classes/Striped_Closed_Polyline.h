#pragma once
#include"../../Graph.h"
#include"../Classes/ConnectionPoint.h"

namespace Graph_lib
{
	class Striped_Closed_Polyline :
		public Closed_polyline
	{
	public:
		Striped_Closed_Polyline();
		void draw_lines() const;
	};
}

