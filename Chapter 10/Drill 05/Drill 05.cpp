// Jared Mathes
// 2018-08-19
// Chapter 10
// Drill 05
// Read back from the file

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

ostream& operator<<(ostream& os, const Point& p)
{
	return os << p.x
		<< ','
		<< p.y;
}

void write_data(vector<Point>& original_points, string& filename)
{
	ofstream ost{ filename };
	if (!ost) error("Cannot open the file ", filename);

	for (auto const& value : original_points)
	{
		ost << value << endl;
	}
}

void read_data(vector<Point> processed_points, string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	for (Point var; ist >> var;)
	{
		processed_points.push_back(var);
	}
	if (ist.eof()) return;
	if (ist.bad()) error("Bad input stream");
}

int main()
try
{
	int counter{ 0 };
	vector<Point> original_points;

	while (counter < 7)
	{
		cout << "Enter in a coordinate in the format x,y : ";
		Point point_input;
		cin >> point_input;
		if (!cin) error("Unexpected EOF or error on stdin");
		original_points.push_back(point_input);

		++counter;
	}

	for (auto const& value : original_points)
	{
		cout << value << endl;
	}

	string filename{ "mydata.txt" };

	write_data(original_points, filename);

	vector<Point> processed_points;

	read_data(processed_points, filename);

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