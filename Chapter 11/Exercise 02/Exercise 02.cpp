// Jared Mathes
// 2018-09-01
// Chapter 11
// Exercise 02
// Output lines from a file that contain a word

#include "../../std_lib_facilities.h"

int main()
try
{
	cout << "Please enter an input file name: ";
	string iname;
	cin >> iname;

	cout << "Please enter a word to search for: ";
	string word;
	cin >> word;

	ifstream ifs{ iname };
	if (!ifs) error("Can't open file ", iname);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	string s;
	int counter{ 0 };

	cout << "Lines containing the word: " << word << endl;
	while (ifs)
	{
		counter++;
		getline(ifs, s);
		stringstream str{ s };
		string b;
		while (str >> b)
		{
			if (b == word) cout << counter << " : " << s << endl;
		}
	}

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