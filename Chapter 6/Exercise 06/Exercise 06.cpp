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

bool conjunctn()
{
	string s = sstr.get();
	if (s == "and" || s == "or" || s == "but")
	{
		return true;
	} 
	else
	{
		return false;
	}
}

bool noun()
{
	string s = sstr.get();
	if (s == "birds" || s == "fish" || s == "C++")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool verb()
{
	string s = sstr.get();
	if (s == "rules" || s == "fly" || s == "swim")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool subject()
{
	string s = sstr.get();
	if (s == "the")     // article before noun, check next string
		return noun();
	else {              // no article, put string back and check if noun
		sstr.putback(s);
		return noun();
	}
}

bool sentence()
{
	return (subject() && verb());
}

int main()
{
	try
	{
		bool is_ok = false;
		while (true)
		{
			// check for a valid sentence
			is_ok = sentence();
			if (!is_ok)
			{
				cout << "Not OK\n";
				return 0;
			}

			// now check for the correct sentence termination sequence
			string s = sstr.get();
			if (s == ".")
			{
				cout << "OK\n";
				return 0;
			}
			// if it's not terminated, put back what we found and check for a conjunction
			else
			{
				sstr.putback(s);
				is_ok = conjunctn();
				if (!is_ok)
				{
					cout << "Not OK\n";
					return 0;
				}
			}
		}
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}