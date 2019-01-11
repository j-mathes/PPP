#include "Pseudo_window.h"

Graph_lib::Pseudo_window::Pseudo_window(Point pp, int ww, int hh, string str)
	:RoundedBox(pp, ww, hh, 5),
	p{ pp },
	w{ ww },
	h{ hh },
	lab{ Point{p.x + 10, p.y + 10}, str },
	inner_border{ Point{p.x + 3, p.y + 13}, w - 6, h - 16 },
	minimize{ Point{p.x + w - 39, p.y + 2}, 10,10 },
	maximize{ Point{p.x + w - 26, p.y + 2}, 10,10 },
	close_window{ Point{p.x + w - 13, p.y + 2}, 10,10 }
{
	lab.set_font(Font::helvetica_bold);
	lab.set_font_size(10);
	lab.set_color(Color::black);
	RoundedBox::set_color(Color::black);
	inner_border.set_color(Color::black);
	minimize.set_color(Color::black);
	maximize.set_color(Color::black);
	close_window.set_color(Color::black);
}

void Graph_lib::Pseudo_window::draw_lines() const
{
	RoundedBox::draw_lines();
	inner_border.draw();
	lab.draw();
	minimize.draw();
	maximize.draw();
	close_window.draw();
}
