// Jared Mathes
// 2018-04-06
// Chapter 4
// Exercise 19
// Name / score pairs

#include "../../std_lib_facilities.h"

int main()
{
	vector<string> name;
	vector<int> score;
	bool duplicate = false;

	cout << "Enter in a name and a score (i.e. Joe 17).\n";
	cout << "Terminate with 'NoName 0'.\n\n";

	for (string a_string; cin >> a_string; )
	{
		int an_int;
		cin >> an_int;

		if (a_string == "NoName" && an_int == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < name.size(); ++i)
				if (a_string == name[i])
				{
					cout << "Duplicate Name: " << a_string;
					duplicate = false;
					error("Duplicate Name");
				}

			if (!duplicate)
			{
				name.push_back(a_string);
				score.push_back(an_int);
			}
		}
	}

	cout << '\n';

	for (int i = 0; i < name.size(); ++i)
	{
		cout << name[i] << ", " << score[i] << '\n';
	}

	return 0;
}