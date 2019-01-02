#include "ConnectionPoint.h"

namespace Graph_lib
{
	bool lie_on_line(Point p1, Point p2, Point current)
	{
		int dxc = current.x - p1.x;
		int dyc = current.y - p1.y;

		int dx1 = p2.x - p1.x;
		int dy1 = p2.y - p1.y;

		if (!(dxc*dy1 - dx1 * dyc)) {
			if (abs(dx1) > abs(dy1)) {
				return dx1 > 0 ? p1.x <= current.x && current.x <= p2.x : p2.x <= current.x && current.x <= p1.x;
			}
			else return dy1 > 0 ? p1.y <= current.y && current.y <= p2.y : p2.y <= current.y && current.y <= p1.y;
		}
		return false;
	}

	bool line_segment_intersection(Point p1, Point p2, Point p3, Point p4, Point &intersect) {
		double y1 = p1.y;
		double y2 = p2.y;
		double y3 = p3.y;
		double y4 = p4.y;
		double x1 = p1.x;
		double x2 = p2.x;
		double x3 = p3.x;
		double x4 = p4.x;

		double denom = (y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1);
		double u1 = (x4 - x3)*(y1 - y3) - (y4 - y3)*(x1 - x3);
		double u2 = (x2 - x1)*(y1 - y3) - (y2 - y1)*(x1 - x3);

		if (denom == 0 && u1 != 0 && u2 != 0) return false;

		u1 = u1 / denom;
		u2 = u2 / denom;

		if (u1 < 0 || u1 > 1 || u2 < 0 || u2 > 1) return false;

		intersect.x = static_cast<int>(x1 + u1 * (x2 - x1));
		intersect.y = static_cast<int>(y1 + u1 * (y2 - y1));
		return true;
	}

	Point point_on_circle(Circle &c, int d)
	{
		double radians = d * 3.141592 / 180;
		Point result;
		result.x = static_cast<int>(c.center().x + c.radius() * cos(radians));
		result.y = static_cast<int>(c.center().y + c.radius() * sin(radians));
		return result;
	}

	Point point_on_ellipse(Ellipse &e, int d)
	{
		double radians = d * 3.141592 / 180;
		Point result;
		result.x = static_cast<int>(e.center().x + e.major() * cos(radians));
		result.y = static_cast<int>(e.center().y + e.minor() * sin(radians));
		return result;
	}

	Point n(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y;
		return result;
	}
	Point n(Circle &c)
	{
		return point_on_circle(c, 270);
	}
	Point n(Ellipse &e)
	{
		return point_on_ellipse(e, 270);
	}

	Point s(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y + r.height();
		return result;
	}
	Point s(Circle &c)
	{
		return point_on_circle(c, 90);
	}
	Point s(Ellipse &e)
	{
		return point_on_ellipse(e, 90);
	}

	Point e(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y + r.height()/2;
		return result;
	}
	Point e(Circle &c)
	{
		return point_on_circle(c, 0);
	}
	Point e(Ellipse &e)
	{
		return point_on_ellipse(e, 0);
	}

	Point w(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x;
		result.y = r.point(0).y + r.height() / 2;
		return result;
	}
	Point w(Circle &c)
	{
		return point_on_circle(c, 180);
	}
	Point w(Ellipse &e)
	{
		return point_on_ellipse(e, 180);
	}

	Point center(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y + r.height() / 2;
		return result;
	}
	Point center(Circle &c)
	{
		return c.center();
	}
	Point center(Ellipse &e)
	{
		return e.center();
	}

	Point ne(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y;
		return result;
	}
	Point ne(Circle &c)
	{
		return point_on_circle(c, 315);
	}
	Point ne(Ellipse &e)
	{
		return point_on_ellipse(e, 315);
	}

	Point nw(Rectangle &r)
	{
		return r.point(0);
	}
	Point nw(Circle &c)
	{
		return point_on_circle(c, 225);
	}
	Point nw(Ellipse &e)
	{
		return point_on_ellipse(e, 225);
	}

	Point se(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y + r.height();
		return result;
	}
	Point se(Circle &c)
	{
		return point_on_circle(c, 135);
	}
	Point se(Ellipse &e)
	{
		return point_on_ellipse(e, 135);
	}

	Point sw(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x;
		result.y = r.point(0).y + r.height();
		return result;
	}
	Point sw(Circle &c)
	{
		return point_on_circle(c, 45);
	}
	Point sw(Ellipse &e)
	{
		return point_on_ellipse(e, 45);
	}
}
