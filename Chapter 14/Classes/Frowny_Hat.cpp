#include "Frowny_Hat.h"

Graph_lib::Frowny_Hat::Frowny_Hat(Point center, int radius)
	:Frowny(center, radius)
{
}

void Graph_lib::Frowny_Hat::draw_lines() const
{
	Graph_lib::Frowny::draw_lines();
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