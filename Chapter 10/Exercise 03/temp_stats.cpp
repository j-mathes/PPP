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
	r.hour = new_hour;
	r.temperature = new_temperature;
	return is;
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
	double total_temperatures{ 0 };
	for (Reading value : temperature_readings)
	{
		total_temperatures += value.temperature;
	}
	return total_temperatures / temperature_readings.size();
}

double calculate_median_temp(const vector<Reading>& temperature_readings)
{
	// calculate median temperatures
	vector<double> temperature_values;
	for (Reading r: temperature_readings)
	{
		temperature_values.push_back(r.temperature);
	}
	int size = temperature_values.size();

	if (size == 0)
	{
		return 0;
	}
	else
	{
		sort(temperature_values.begin(), temperature_values.end());
		if (size % 2 == 0)
		{
			return (temperature_values[size / 2 - 1] + temperature_values[size / 2]) / 2;
		}
		else
		{
			return temperature_values[size / 2];
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