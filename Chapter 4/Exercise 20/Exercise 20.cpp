// Jared Mathes
// 2018-04-09
// Chapter 4
// Exercise 20
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

	// Now we let the user enter in a name.  If we find the name, we output the score for that name.  If not, we reply that the name is not found.

	cout << "\n\nEnter a name to find the score.\n";
	for (string a_string; cin >> a_string;)
	{
		bool found = false;
		int ind;
		for (int i = 0; i < name.size(); ++i)
		{
			if (a_string == name[i])
			{
				found = true;
				ind = i;
				break;
			}
		}

		if (found)
		{
			cout << "\nThe score for " << name[ind] << " is " << score[ind] << ".\n";
		}
		else
		{
			cout << "\nCannot find the name " << a_string << ".\n";
		}
	}

	return 0;
}