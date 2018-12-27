#include "ConnectionPoint.h"

namespace Graph_lib
{
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
