// Jared Mathes
// 2018-04-09
// Chapter 4
// Exercise 21
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

	// Now we let the user enter in a score.  If we find the score, we output the name for that score.  If not, we reply that the score is not found.

	cout << "\n\nEnter a score to find the name.\n";
	for (int an_int; cin >> an_int;)
	{
		bool found = false;
		int ind;
		for (int i = 0; i < name.size(); ++i)
		{
			if (an_int == score[i])
			{
				found = true;
				ind = i;
				break;
			}
		}

		if (found)
		{
			cout << "\nThe name for score " << score[ind] << " is " << name[ind] << ".\n";
		}
		else
		{
			cout << "\nCannot find the score " << an_int << ".\n";
		}
	}

	return 0;
}