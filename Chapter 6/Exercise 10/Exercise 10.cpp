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

//------------------------------------------------------------------------------
// Given a number, return the factorial
int factorial(int num)
{
	if (num > 0)
	{
		int answer{ num };
		for (int i = num - 1; i > 0; --i)
		{
			answer *= i;
		}
		return answer;
	}
	else
	{
		return 1;
	}
}

//------------------------------------------------------------------------------
// Permutation
int permutation(int a, int b)
{
	int answer = factorial(a) / factorial(a - b);
	return answer;
}
//------------------------------------------------------------------------------
// Combination
int combination(int a, int b)
{
	int answer = permutation(a, b) / factorial(b);
	return answer;
}
int main()
{
	try
	{
		while (true)
		{
			cout << "\n";
			cout << "Enter the first integer number.\n";
			cout << "> ";

			string input_1 = sstr.get();
			if (!is_digits(input_1)) throw std::invalid_argument("Input needs to be digits");
			int first_num = std::stoi(input_1);

			cout << "\n";
			cout << "Enter the second integer number.\n";
			cout << "> ";

			string input_2 = sstr.get();
			if (!is_digits(input_2)) throw std::invalid_argument( "Input needs to be digits" );
			int second_num = std::stoi(input_2);

			cout << "\n";
			cout << "Enter 'P' for Permutations or 'C' for Combinations.\n";
			cout << "> ";

			char oper;
			cin >> oper;

			switch (oper)
			{
			case 'P':
			case 'p':
				cout << "\n";
				cout << "The Permutation of " << first_num << " and " << second_num << " is " << permutation(first_num, second_num) << ".\n";
				break;
			case 'C':
			case 'c':
				cout << "\n";
				cout << "The Combination of " << first_num << " and " << second_num << " is " << combination(first_num, second_num) << ".\n";
				break;
			default:
				cout << "\n";
				cout << "Not a valid choice.\n";
				break;
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