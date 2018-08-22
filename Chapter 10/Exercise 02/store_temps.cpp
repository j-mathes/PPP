// Jared Mathes
// 2018-08-22
// Chapter 10
// Exercise 02
// Store temperature data in file

#include "../../std_lib_facilities.h"

struct Reading 
{
	int hour;
	double temperature;
};

double frand(double fMin, double fMax)
{
	return fMin + (rand() / (RAND_MAX / fMax - fMin));
}

ostream& operator<<(ostream& os, const Reading& r)
{
	return os << r.hour
		<< ' '
		<< r.temperature;
}

void write_readings(const vector<Reading>& r, const string& filename)
{
	ofstream ost{ filename };
	if (!ost) error("Cannot open the file ", filename);

	for (auto const& value : r)
	{
		ost << value << endl;
	}
}

int main()
try
{
	vector<Reading> temperature_readings;
	string filename{ "raw_temps.txt" };

	int hour_counter{ 0 };
	for (int i=0; i<50; ++i)
	{
		Reading new_reading;
		new_reading.hour = hour_counter;
		new_reading.temperature = frand(0, 35);
		temperature_readings.push_back(new_reading);
		++hour_counter;
		if (hour_counter > 23)
		{
			hour_counter = 0;
		}
	}

	write_readings(temperature_readings, filename);

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