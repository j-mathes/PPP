// Jared Mathes
// 2018-07-26
// Chapter 8
// Exercise 11
// Function to compute smallest, largest, mean, and median elements in a vector

#include "../../std_lib_facilities.h"

class Element_Results
{
public:
	double smallest;
	double largest;
	double mean;
	double median;
};

double maxv(vector<double>& v)
{
	double result{ 0 };
	for (int i{ 0 }; i < v.size() - 1; ++i)
	{
		if (v[i + 1] > result)
		{
			result = v[i + 1];
		}
	}
	return result;
}

double minv(vector<double>& v)
{
	double result = v[0];
	for (int i{ 0 }; i < v.size() - 1; ++i)
	{
		if (v[i + 1] < result)
		{
			result = v[i + 1];
		}
	}
	return result;
}

double meanv(vector<double>& v)
{
	double result{ 0 };
	double temp{ 0 };
	for (int i{ 0 }; i < v.size(); ++i)
	{
		temp += v[i]; 
	}
	result = temp / v.size() + 1;
	return result;
}

double medianv(vector<double>& v)
{
	vector<double> temp_v = v;
	sort(temp_v.begin(), temp_v.end());
	int n = int(v.size() / 2);
	if (n % 2 == 0)
	{
		return temp_v[temp_v.size() / 2];
	}
	else
	{
		return (temp_v[n] + temp_v[n - 1]) / 2.0;
	}
}

Element_Results compute_vector(vector<double>& v)
{
	if (v.size() == 0)
	{
		error("No elements in the vector.");
	}
	Element_Results vector_results;
	double result = v[0];
	if (v.size() == 1)
	{
		vector_results.smallest = result;
		vector_results.largest = result;
		vector_results.mean = result;
		vector_results.median = result;
	}
	else
	{
		vector_results.smallest = minv(v);
		vector_results.largest = maxv(v);
		vector_results.mean = meanv(v);
		vector_results.median = medianv(v);
	}

	return vector_results;
}

int main()
try
{
	vector<double> my_vector{ 1.5, 4.3, 2.6, 19.1, 12.0, 17.98 };

	Element_Results results = compute_vector(my_vector);
	cout << "smallest: " << results.smallest << endl;
	cout << "largest : " << results.largest << endl;
	cout << "mean    : " << results.mean << endl;
	cout << "median  : " << results.median << endl;
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