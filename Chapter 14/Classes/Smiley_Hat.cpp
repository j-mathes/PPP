#include "Smiley_Hat.h"

Graph_lib::Smiley_Hat::Smiley_Hat(Point center, int radius)
	:Smiley(center, radius)
{
}

void Graph_lib::Smiley_Hat::draw_lines() const
{
	Graph_lib::Smiley::draw_lines();
	Graph_lib::Line brim{
		Point{center().x - static_cast<int>(radius() * 0.8), center().y - radius()},
		Point{center().x + static_cast<int>(radius() * 0.8), center().y - radius()}
	};
	brim.draw();
	Graph_lib::Rectangle cap{
		Point{center().x - static_cast<int>(radius() * 0.3), center().y - radius() - static_cast<int>(radius() * 0.7)},
		Point{center().x + static_cast<int>(radius() * 0.3), center().y - radius()}
	};
	cap.draw_lines();
}