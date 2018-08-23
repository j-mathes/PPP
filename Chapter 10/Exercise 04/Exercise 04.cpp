// Jared Mathes
// 2018-08-22
// Chapter 10
// Exercise 04
// Temperature data with conversion between C and F

#include "../../std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;
	char temperature_units;
};

double frand(double fMin, double fMax)
{
	return fMin + (rand() / (RAND_MAX / fMax - fMin));
}

ostream& operator<<(ostream& os, const Reading& r)
{
	return os << r.hour
		<< ' '
		<< r.temperature
		<< ' '
		<< r.temperature_units;
}

istream& operator>>(istream& is, Reading& r)
{
	int new_hour;
	double new_temperature;
	char new_temperature_units;
	is >> new_hour >> new_temperature >> new_temperature_units;
	if (is.eof())
		return is;
	r.hour = new_hour;
	r.temperature = new_temperature;
	r.temperature_units = new_temperature_units;
	return is;
}

void convert_c_to_f(Reading& r)
{
	if (r.temperature_units == 'c' || r.temperature_units == 'C')
	{
		double tmp = r.temperature;
		r.temperature = (tmp * (9 / 5)) + 32;
		r.temperature_units = 'f';
	}
}

void read_readings(vector<Reading>& vector_of_readings, const string& filename)
{
	ifstream ist{ filename };
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	for (Reading var; ist >> var;)
	{
		convert_c_to_f(var);
		vector_of_readings.push_back(var);
	}
	if (ist.eof()) return;
	if (ist.bad()) error("Bad input stream");
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
	for (Reading r : temperature_readings)
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

	int hour_counter{ 0 };
	for (int i = 0; i < 50; ++i)
	{
		Reading new_reading;
		new_reading.hour = hour_counter;
		new_reading.temperature = frand(0, 35);
		new_reading.temperature_units = 'c';
		temperature_readings.push_back(new_reading);
		++hour_counter;
		if (hour_counter > 23)
		{
			hour_counter = 0;
		}
	}

	write_readings(temperature_readings, filename);

	vector<Reading> new_temperature_readings;

	read_readings(new_temperature_readings, filename);

	cout << "Mean temperature: " << calculate_mean_temp(new_temperature_readings) << endl;

	cout << "Median temperature: " << calculate_median_temp(new_temperature_readings) << endl;

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