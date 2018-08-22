// Jared Mathes
// 2018-08-22
// Chapter 10
// Exercise 03
// Read temperature in data file and calculate statistics

#include "../../std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;
};

ostream& operator<<(ostream& os, const Reading& r)
{
	return os << r.hour
		<< ' '
		<< r.temperature;
}

istream& operator>>(istream& is, Reading& r)
{
	int new_hour;
	double new_temperature;
	is >> new_hour >> new_temperature;
	if (is.eof()) 
		return is;
	else
		error("bad reading");

	r.hour = new_hour;
	r.temperature = new_temperature;
}

void read_readings(vector<Reading>& vector_of_readings, const string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	for (Reading var; ist >> var;)
	{
		vector_of_readings.push_back(var);
	}
	if (ist.eof()) return;
	if (ist.bad()) error("Bad input stream");
}

double calculate_mean_temp(const vector<Reading>& temperature_readings)
{
	// calculate mean temperatures
	int counter{ 0 };
	double total_temperatures;
	for (auto const& value : temperature_readings)
	{
		total_temperatures += value.temperature;
		++counter;
	}
	return total_temperatures / (double)counter;
}

double calculate_median_temp(const vector<Reading>& temperature_readings)
{
	// calculate median temperatures
	size_t size = temperature_readings.size();

	if (size == 0)
	{
		return 0;
	}
	else
	{
		sort(temperature_readings.begin(), temperature_readings.end());
		if (size % 2 == 0)
		{
			return (temperature_readings[size / 2 - 1].temperature + temperature_readings[size / 2].temperature) / 2;
		}
		else
		{
			return temperature_readings[size / 2].temperature;
		}
	}
}

int main()
try
{
	vector<Reading> temperature_readings;
	string filename{ "raw_temps.txt" };

	read_readings(temperature_readings, filename);

	cout << "Mean temperature: " << calculate_mean_temp(temperature_readings) << endl;

	cout << "Median temperature: " << calculate_median_temp(temperature_readings) << endl;

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