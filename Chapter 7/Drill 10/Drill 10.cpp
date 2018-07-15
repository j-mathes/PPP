
/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

/*
Simple Calculator

This program implements a basic expression calculator.
Input from cin; output to cout.

kind is the key field, and has the following values and meanings:
number - value contains a value
name - variable name contains a name
let / # - it is a let statement
squrt - it is a sqrt function
pw - It is a power function
quit - it is a quit statement
print - it is a print statement
other - it is an operator character

The grammar for input is:

Statement:
Expression
Print
Quit

Print:
;

Quit:
q

Expression:
Term
Expression + Term
Expression – Term

Term:
Primary
Term * Primary
Term / Primary
Term % Primary

Primary:
Number
( Expression )
– Primary
+ Primary

Number:
floating-point-literal

Input comes from cin through the Token_stream called ts.

Defining Names:
let (name) =
Defines a name that can be used as a substitute.  'let' must be lower case.
*/

#include "../../std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }					// initialize kind with ch
	Token(char ch, double val) :kind(ch), value(val) { }	// initialize kind and value
	Token(char ch, string n) :kind{ ch }, name{ n } {}		// initialize kind and name
};

/* This is a token stream, with buffer being the lookahead character
if full is true.  buffer is initialized more cleanly.  See
below for the methods.
*/
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

// Definitions for Token kind codes.
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squrt = 'S';
const char pw = 'P';

// Get a character from a Token stream, filling from cin, as necessary.
// It detects bad input, crudely, and handles EOF correctly.
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':	// we need to add the comma so the parser knows hot to treat it when encountered.
		return Token(ch);
	case '#':
		return Token(let);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}

	// Anything else is a name.  I don't like reading beyond the end, and
	// backing off, but the standard requires it to work even at EOF.
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(quit);
			if (s == "sqrt") return Token(squrt);
			if (s == "pow") return Token(pw);
			return Token(name, s);
		}
		error("Bad token");
		return Token(' ');
	}
}

// Skip characters until its argument is matched, and throw that character away.
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

//  This is a named variable.
struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

// The vector of all active variables.
vector<Variable> names;

//  Get the value of a variable, or fail if no match.
double get_value(string s)
{
	for (size_t i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
	return 0.0;
}

//  Set the value of a variable, or fail if no match.
void set_value(string s, double d)
{
	for (size_t i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

// Check if a variable exists.
bool is_declared(string s)
{
	for (size_t i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

// The token stream.
Token_stream ts;

double expression();

// Power function
double powerup()
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected");
	double x = expression();
	t = ts.get();
	if (t.kind != ',') error("',' expected");
	double y = expression();
	int n = int(y);
	if (n != y) error("non-integral powers not supported");
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	y = 1.0;
	if (n < 0)
	{
		for (int i = 0; i < n; ++i)
		{
			y /= x;
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			y *= x;
		}
	}
	return y;
}

// Read a primary (value, operator, etc. or a compound expression)
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;	// this was missing
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case squrt:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		ts.unget(t);
		double x = primary();
		if (x < 0.0) error("Square root of a negative number");
		return sqrt(x);
	}
	case pw:
	{
		return powerup();
	}
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
		return 0.0;
	}
}

// Read a multiplicative expression.
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// Read an additive expression.
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// Read a variable declaration.
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

// Read a statement.
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

// Skip to the next print character.
void clean_up_mess()
{
	ts.ignore(print);
}

//Mnemonics for output strings.
const string prompt = "> ";
const string result = "= ";

// The main calculation loop.
void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	Token k(name, "k");
	names.push_back(Variable("k", 1000.0));	// predefined value k
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}