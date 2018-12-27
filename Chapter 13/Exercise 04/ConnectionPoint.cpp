#include "ConnectionPoint.h"

namespace Graph_lib
{

	Point n(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y;
		return result;
	}

	Point s(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y + r.height();
		return result;
	}

	Point e(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y + r.height()/2;
		return result;
	}

	Point w(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x;
		result.y = r.point(0).y + r.height() / 2;
		return result;
	}

	Point center(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width() / 2;
		result.y = r.point(0).y + r.height() / 2;
		return result;
	}

	Point ne(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y;
		return result;
	}

	Point nw(Rectangle &r)
	{
		return r.point(0);
	}

	Point se(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x + r.width();
		result.y = r.point(0).y + r.height();
		return result;
	}

	Point sw(Rectangle &r)
	{
		Point result;
		result.x = r.point(0).x;
		result.y = r.point(0).y + r.height();
		return result;
	}

}
