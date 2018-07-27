// Jared Mathes
// 2018-07-26
// Chapter 8
// Exercise 09
// Two vector function

#include "../../std_lib_facilities.h"

double calculate_index(vector<double>& price, vector<double>& weight)
{
	double result{ 0.0 };
	if (price.size() == weight.size())
	{
		for (int i{ 0 }; i < price.size(); ++i)
		{
			result += price[i] * weight[i];
			cout << result << endl;
		}
		return result;
	} 
	else
	{
		error("The vectors price and weight are not the same size");
	}
}

int main()
try
{
	vector<double> price{ 1.5, 4.3, 2.6, 1.1, 12.0 };
	vector<double> weight{ 12.3, 1.7, 34.2, 9.6, 42.3 };

	double index = calculate_index(price, weight);
	cout << "-------------" << endl;
	cout << index << endl;
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