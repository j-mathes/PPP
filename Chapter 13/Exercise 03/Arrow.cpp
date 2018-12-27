#include "Arrow.h"

void Graph_lib::Arrow::draw_lines() const
{
	for (int i = 1; i < number_of_points(); i += 2)
		fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);

	Vec leftArrowHead;
	Vec rightArrowHead;
	arrowhead(p1, p2, leftArrowHead, rightArrowHead);

	Point la{ static_cast<int>(leftArrowHead.x), static_cast<int>(leftArrowHead.y) };
	Point ra{ static_cast<int>(rightArrowHead.x), static_cast<int>(rightArrowHead.y) };
	fl_line(la.x, la.y, p2.x, p2.y, ra.x, ra.y);
}

void Graph_lib::Arrow::arrowhead(Vec A, Vec B, Vec& v1, Vec& v2) const
{
	float h = static_cast<float>(arrowHead_length) * sqrtf(3);
	float w = static_cast<float>(arrowHead_length);
	Vec U = (B - A) / (B - A).length();
	Vec V;
	V.x = -(U.y);
	V.y = U.x;
	v1 = B - h * U + w * V;
	v2 = B - h * U - w * V;
}