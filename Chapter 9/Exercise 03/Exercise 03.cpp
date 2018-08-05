// Jared Mathes
// 2018-08-04
// Chapter 9
// Exercise 03
// Name_pairs class

#include "../../std_lib_facilities.h"

class Name_pairs
{
public:
	void read_names();
	void read_ages();
	void sort_data();
	const vector<string>& get_names() const { return name; }
	const vector<double>& get_ages() const { return age; }

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

void Name_pairs::sort_data()
{
	vector<string> name_copy = name;
	vector<double> ages_copy;

	sort(name.begin(), name.end());
	for (size_t i = 0; i < name.size(); ++i)
	{
		ages_copy.push_back(age[find_index(name_copy, name[i])]);
	}
	age = ages_copy;
}

int Name_pairs::find_index(const vector<string> string_vector, const string& s)
{
	for (size_t i = 0; i < string_vector.size(); ++i)
	{
		if (string_vector[i] == s)
		{
			return i;
		}

	}
	error("That name is not found.");
}

ostream& operator<<(ostream& os, const Name_pairs& n)
{
	// get the data by reference
	const vector<string>& name{ n.get_names() };
	const vector<double>& age{ n.get_ages() };

	for (size_t i = 0; i < name.size(); ++i)
	{
		// now we can refer to the reference in the output loop
		os << name[i] << ", " << age[i] << endl;
	}
	return os;
}

// here we are using the == operator to compare vectors that is built into the vector
bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	return (a.get_names() == b.get_names() && a.get_ages() == b.get_ages());
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{

	return !(a == b);
}

int main()
try
{
	Name_pairs my_pairs;
	my_pairs.read_names();
	my_pairs.read_ages();
	cout << my_pairs;
	my_pairs.sort_data();
	cout << my_pairs;

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

