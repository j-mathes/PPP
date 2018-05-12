// Jared Mathes
// 2018-05-11
// Chapter 6
// Exercise 04
// Name / score pairs using a class

#include "../../std_lib_facilities.h"

class Name_value
{
public:
	string name;
	int score;
};

int main()
{
	vector<Name_value> score_pair;
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
			for (int i = 0; i < score_pair.size(); ++i)
				if (a_string == score_pair[i].name)
				{
					cout << "Duplicate Name: " << a_string;
					duplicate = false;
					error("Duplicate Name");
				}

			if (!duplicate)
			{
				Name_value temp{a_string, an_int};
				score_pair.push_back(temp);
			}
		}
	}

	cout << '\n';

	for (int i = 0; i < score_pair.size(); ++i)
	{
		cout << score_pair[i].name << ", " << score_pair[i].score << '\n';
	}

	return 0;
}