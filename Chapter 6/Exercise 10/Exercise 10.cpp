// Jared Mathes
// 2018-06-12
// Chapter 6
// Exercise 10
// Permutations or Combinations

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
// The get() member function gets the next string or removes from the buffer if we already have one:
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

//------------------------------------------------------------------------------
// Test a string for non-digit characters
bool is_digits(const std::string &str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}

int main()
{
	try
	{
		while (true)
		{
			cout << "Enter a number up to four digits long.\n";
			cout << "> ";

			string s = sstr.get();
			
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