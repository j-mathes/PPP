//----------------------------------------------------------------------------
// File:	Drill B.cpp
// Date:	2019-01-22
// Author:	JaredM
//----------------------------------------------------------------------------
// Solution:Chapter 15
// Project:	Drill B
//----------------------------------------------------------------------------
// Description: Class Definition
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

struct Person
{
	Person(string n = "temp", int a = 1)
		:name{ n }, age{ a }
	{
		if (age < 0 || age > 150)
		{
			error("Age must be between 0 and 150");
		}
	}

	string mName() const { return name; }
	int mAge() const { return age; }

	friend ostream &operator <<(ostream &output, Person person)
	{
		output << name << "," << age;
	}

	friend istream &operator >>(istream &input, Person &person)
	{
		input >> person.name;
		input >> person.age;

		return input;
	}

private:
	string name;
	int age;
};

//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	Person Goofy{"Goofy", 63};

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