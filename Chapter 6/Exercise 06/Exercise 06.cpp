// Jared Mathes
// 2018-06-04
// Chapter 6
// Exercise 06
// Check if a program is a sentence
/*
Implements this grammar:
	Sentence:
		Subject Verb
		Sentence Conjunction Sentence
	Subject:
		Noun
		"the" Noun
	Conjunction:
		"and"
		"or"
		"but"
	Noun:
		"birds"
		"fish"
		"C++"
	Verb:
		"rules"
		"fly"
		"swim"
and checks if an entered sentence is correct according to it or not.
*/

#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter in a sentence and I will validate it.\n";
	cout << "To be valid, the sentence should be terminated with a space followed by a period.\n";
	cout << "i.e ' .'\n\n";

	vector<string> a_sentence;

	for (string a_string; cin >> a_string; )
	{

		if (a_string != ".")
		{
			true; 
		}
		else
		{
			false;
		}
	}

	return 0;
}