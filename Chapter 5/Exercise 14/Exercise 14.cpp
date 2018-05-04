// Jared Mathes
// 2018-05-03
// Chapter 5
// Exercise 14
// Days of the week and numbers

#include "../../std_lib_facilities.h"

void output_vector(vector<int> &day_of_week, string name_of_day)
{
	cout << "List of entries for " << name_of_day << ".\n";
	int sum{ 0 };
	
	if (day_of_week.size() > 0)
	{
		for (int i = 0; i < day_of_week.size(); ++i)
		{
			cout << day_of_week[i] << " ";
			sum += day_of_week[i];
		}
		cout << "\n\nThe sum of all entries for " << name_of_day << " are " << sum << ".\n\n";
	} 
	else
	{
		cout << name_of_day << " does not have any entries.\n\n";
	}
}

int main()
{
	vector<int> sunday;
	vector<int> monday;
	vector<int> tuesday;
	vector<int> wednesday;
	vector<int> thursday;
	vector<int> friday;
	vector<int> saturday;

	vector<int> rejected;

	bool cont {true};

	cout << "Enter a day of the week and an integer for that day.  Enter 'Stop' with a value of '0' to end.\n\n";

	while (cont == true)
	{
		string input;
		cin >> input;

		int value;
		cin >> value;

		if (input == "Sunday" || input == "sunday" || input == "Sun" || input == "sun")
		{
			sunday.push_back(value);
		} 
		else if (input == "Monday" || input == "monday" || input == "Mon" || input == "mon")
		{
			monday.push_back(value);
		}
		else if (input == "Tuesday" || input == "tuesday" || input == "Tue" || input == "tue")
		{
			tuesday.push_back(value);
		}
		else if (input == "Wednesday" || input == "wednesday" || input == "Wed" || input == "wed")
		{
			wednesday.push_back(value);
		}
		else if (input == "Thursday" || input == "thursday" || input == "Thu" || input == "thu")
		{
			thursday.push_back(value);
		}
		else if (input == "Friday" || input == "friday" || input == "Fri" || input == "fri")
		{
			friday.push_back(value);
		}
		else if (input == "Saturday" || input == "saturday" || input == "Sat" || input == "sat")
		{
			saturday.push_back(value);
		}
		else if (input == "Stop" || input == "stop")
		{
			cont = false;
		}
		else
		{
			rejected.push_back(value);
		}
	}

	output_vector(sunday, "Sunday");
	output_vector(monday, "Monday");
	output_vector(tuesday, "Tuesday");
	output_vector(wednesday, "Wednesday");
	output_vector(thursday, "Thursday");
	output_vector(friday, "Friday");
	output_vector(saturday, "Saturday");

	cout << "There were " << rejected.size() << " rejected entries.\n\n";

	return 0;
}