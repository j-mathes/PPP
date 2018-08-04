// Jared Mathes
// 2018-08-04
// Chapter 9
// Exercise 02
// Name_pairs class

#include "../../std_lib_facilities.h"

class Name_pairs
{
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort_data();
private:
	vector<string> name;
	vector<double> age;
	int find_index(const vector<string>, const string&);
};

void Name_pairs::read_names()
{
	while (true)
	{
		cout << "Enter a name (EOF to quit): ";
		string input;
		cin >> input;
		if (!cin) error("Unexpected end of file or error on stdin.");
		if (input == "EOF")
		{
			cout << endl << endl;
			break;
		}
		name.push_back(input);
		cout << endl;
	}
}

void Name_pairs::read_ages()
{
	for (string string_name : name)
	{
		cout << "Enter the age of " << string_name << ": ";
		double input;
		cin >> input;
		age.push_back(input);
	}
}

void Name_pairs::print() const
{
	for (int i=0; i<name.size(); ++i)
	{
		cout << name[i] << ", " << age[i] << endl;
	}
}

void Name_pairs::sort_data()
{
	vector<string> name_copy = name;
	vector<double> ages_copy;

	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); ++i)
	{
		ages_copy.push_back(age[find_index(name_copy, name[i])]);
	}
	age = ages_copy;
}

int Name_pairs::find_index(const vector<string> string_vector, const string& s)
{
	for (int i = 0; i < string_vector.size(); ++i)
	{
		if (string_vector[i] == s)
		{
			return i;
		}
		
	}
	error("That name is not found.");
}

int main()
try
{
	Name_pairs my_pairs;
	my_pairs.read_names();
	my_pairs.read_ages();
	my_pairs.print();
	my_pairs.sort_data();
	my_pairs.print();

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

