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

class String_stream {
public:
	String_stream();			// make a String_stream that reads from cin
	string get();				// get a String (get() is defined elsewhere)
	void putback(string t);		// put a String back
private:
	bool full;					// is there a String in the buffer?
	string buffer;				// here is where we keep a String put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
String_stream::String_stream()
	:full(false), buffer("")		// no String in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the String_stream's buffer:
void String_stream::putback(string t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

string String_stream::get()
{
	if (full) {       // do we already have a String ready?
					  // remove String from buffer
		full = false;
		return buffer;
	}

	string s = "";
	cin >> s;
	return s;
}

String_stream sstr;

bool conjunction()
{

}

bool noun()
{

}

bool verb()
{

}

bool subject()
{

}

bool sentence()
{

}

int main()
{
	cout << "Enter in a sentence and I will validate it.\n";
	cout << "To be valid, the sentence should be terminated with a space followed by a period.\n";
	cout << "i.e ' .'\n\n";

	return 0;
}