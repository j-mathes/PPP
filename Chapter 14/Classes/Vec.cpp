#include "Vec.h"


//----------------------------------------------------------------------------
// Operator overloads
//----------------------------------------------------------------------------
Graph_lib::Vec Graph_lib::operator-(const Vec &v1, const Vec &v2)
{
	Vec v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
};

Graph_lib::Vec Graph_lib::operator+(const Vec &v1, const Vec &v2)
{
	Vec v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return v;
};

Graph_lib::Vec Graph_lib::operator/(const Vec &v1, const float &number)
{
	Vec v;
	v.x = v1.x / number;
	v.y = v1.y / number;
	return v;
};

Graph_lib::Vec Graph_lib::operator*(const Vec &v1, const float &number)
{
	Vec v;
	v.x = v1.x * number;
	v.y = v1.y * number;
	return v;
};

Graph_lib::Vec Graph_lib::operator*(const float &number, const Vec &v1)
{
	Vec v;
	v.x = v1.x * number;
	v.y = v1.y * number;
	return v;
};