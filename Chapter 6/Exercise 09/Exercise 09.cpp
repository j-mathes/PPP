// Jared Mathes
// 2018-06-11
// Chapter 6
// Exercise 09
// Read digits and compose into integers

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

			vector<int> digits;
			int thousands = 0;
			int hundreds = 0;
			int tens = 0;
			int ones = 0;

			string s = sstr.get();
			if (s.size() > 3)
			{
				cout << "Length of entry must be 4 digits or less.\n";
				break;
			}
			else if (is_digits(s) == false)
			{
				cout << "Entry must be digits.\n";
				break;
			}
			else
			{
				for (int i = s.size(); i > 0; --i)
				{
					digits.push_back(s[i] - '0');
				}

				// possible range issues if the number has less than 4 digits
				if (s.size() == 3) thousands = digits[3];
				if (s.size() >= 2) hundreds = digits[2];
				if (s.size() >= 1) tens = digits[1];
				ones = digits[0];

				cout << "\n";
				cout << s << " is ";
				if (thousands > 0) cout << thousands << " thousands and " << hundreds << " hundreds and " << tens << " tens and " << ones << " ones.\n";
				else if (hundreds > 0) cout << hundreds << " hundreds and " << tens << " tens and " << ones << " ones.\n";
				else if (tens > 0) cout << tens << " tens and " << ones << " ones.\n";
				else cout << ones << " ones.\n";
				cout << "\n";
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