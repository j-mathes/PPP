#pragma once
#include "../../Graph.h"

namespace Graph_lib
{
	class Vec
	{
	public:
		Vec()
		{
			x = 0;
			y = 0;
		}

		Vec(float xx, float yy)
			:x{ xx }, y{ yy }
		{}

		Vec(Graph_lib::Point p)
		{
			x = static_cast<float>(p.x);
			y = static_cast<float>(p.y);
		}

		Vec(int xx, int yy)
		{
			x = static_cast<float>(xx);
			y = static_cast<float>(yy);
		}

		float length()
		{
			double distance;
			distance = (this->x * this->x) + (this->y * this->y);
			return (float)sqrt(distance);
		}

		float x;
		float y;
	private:
	};

	Vec operator-(const Vec &v1, const Vec &v2);
	Vec operator+(const Vec &v1, const Vec &v2);
	Vec operator/(const Vec &v1, const float &number);
	Vec operator*(const Vec &v1, const float &number);
	Vec operator*(const float &number, const Vec &v1);
}
