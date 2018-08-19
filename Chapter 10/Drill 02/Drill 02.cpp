// Jared Mathes
// 2018-08-19
// Chapter 10
// Drill 02
// Working with points

#include "../../std_lib_facilities.h"

struct Point
{
	int x;
	int y;
};

istream& operator>>(istream& is, Point& p)
// read a point from is to p
// format is x,y
// check format but don't both with data validity
{
	char ch1;				// character input - to hold a comma
	int x_coord;
	int y_coord;
	is >> x_coord >> ch1 >> y_coord;
	if (!is || ch1 != ',') error("bad reading");

	p.x = x_coord;
	p.y = y_coord;

	return is;
}

int main()
try
{
	int counter{ 0 };
	vector<Point> original_points;

	while(counter < 7)
	{
		cout << "Enter in a coordinate in the format x,y : ";
		Point point_input;
		cin >> point_input;
		if (!cin) error("Unexpected EOF or error on stdin");
		original_points.push_back(point_input);

		++counter;
	}
	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}