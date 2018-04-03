/*
Jared Mathes
2018-04-02
Chapter 4
Exercise 01 - Try This 4.6.4
Bleep
*/
#include "../../std_lib_facilities.h"

int main()
{
	vector<string> words;
	string disliked = "Broccoli";

	cout << "Enter in some words. >";
	for (string input; cin>>input;)
	{
		words.push_back(input);
	}

	for (int i{ 0 }; i<words.size(); ++i)
	{
		if (words[i] == disliked)
		{
			cout << "Bleep! ";
		}
		else
		{
			cout << words[i] << " ";
		}
	}
	return 0;
}