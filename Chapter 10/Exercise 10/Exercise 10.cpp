// Jared Mathes
// 2018-08-26
// Chapter 10
// Exercise 10
// Simple Calculator
// Add reading from and writing to a file
// http://people.ds.cam.ac.uk/nmm1/C++/Exercises/Chapter_10/ex_10.cpp

//
//This program implements a basic expression calculator.
//Input from cin; output to cout.
//
//kind is the key field, and has the following values and meanings:
//number - value contains a value
//name - variable name contains a name
//let / # - it is a let statement
//squrt - it is a sqrt function
//pw - It is a power function
//quit / exit - it is a quit statement
//print - it is a print statement
//other - it is an operator character
//
//The grammar for input is:
//
//Statement:
//	Declaration
//	Expression
//
//Declaration:
//	"let" Name "=" Expression
//	"const" Name "=" Expression
//
//Print:
//	;
//
//Exit:
//Quit:
//	q
//
// Help:
// h or H
//
//Expression:
//	Term
//	Expression + Term
//	Expression – Term
//
//Term:
//	Primary
//	Term * Primary
//	Term / Primary
//	Term % Primary
//
//Primary:
//	Number
//	Name
//	( Expression )
//	– Primary
//	+ Primary
//
//Number:
//	floating-point-literal
//
//Name:
//	[a-zA-Z][a-zA-Z_0-9]*	// a letter followed by zero or more letters, underscores, and digits
//							// note that I decided not to start a name with an underscore
//							// just because I consider it ugly)
//
//Input comes from cin through the Token_stream called ts.
//
//Defining Names:
//	let (name) =
//	cont (name = 
//	Defines a name that can be used as a substitute.  'let' must be lower case.
//

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------
// Definitions for Token kind codes.
const char number = '8';
const char quit = 'Q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const char con = 'C';				// const declaration token
const char help = 'H';
const string declkey = "let";		// declaration keyword 
const string constkey = "const";	// const keyword
const char squrt = 'S';
const char pw = 'P';
const char from_file = 'F';
const char to_file = 'T';

//Mnemonics for output strings.
const string prompt = "> ";
const string result = "= ";

// Flag to determine if we are outputting to a file
bool output_to_file = false;
ofstream output;

// depending on where output is going, send to cerr or the ofstream
void diagnose(const string & arg) 
{
	if (output_to_file) output << arg << endl;
	cerr << arg << endl;
}

//------------------------------------------------------------------------------
// Token class definition
class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }					// initialize kind with ch
	Token(char ch, double val) :kind(ch), value(val) { }	// initialize kind and value
	Token(char ch, string n) :kind{ ch }, name{ n } { }		// initialize kind and name
};

//------------------------------------------------------------------------------
// This is a token stream, with buffer being the lookahead character
// if full is true.  buffer is initialized more cleanly.  See
// below for the methods.
//
class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char);
	string readname();
	void openfile(const string& arg);
	void closefile();
	bool primary() { return using_cin; }
	const string& where() { return filename; }

private:
	bool full;
	Token buffer;
	bool using_cin;
	ifstream file;
	string filename;
};

//------------------------------------------------------------------------------
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0), using_cin(true), filename("<cin>")    // no Token in buffer
{
}

//------------------------------------------------------------------------------
// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

string Token_stream::readname() {
	if (!using_cin) error("Nested file access is not allowed");
	string x;
	cin >> x;    // This is a bit nasty ....
	if (!cin) error("Bad filename");
	return x;
}

void Token_stream::openfile(const string & arg) {
	if (!using_cin) error("Nested file reading is not allowed");
	file.open(arg.c_str());
	if (!file) error("Unable to open file");
	using_cin = false;
	filename = arg;
}

void Token_stream::closefile() {
	if (using_cin) error("No file is currently open");
	file.close();  // Error checking on close is tricky in C++
	using_cin = true;
	filename = "<cin>";
}

//------------------------------------------------------------------------------
// Get a character from a Token stream, filling from cin, as necessary.
// It detects bad input, crudely, and handles EOF correctly.
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	//cin >> ch;	// note that >> skips whitespace (space, newline, tab, etc.)
	if (using_cin)
	{
		cin.get(ch);	// note that cin.get() does NOT skip whitespace
		if (!cin) return Token(quit);
	}
	else
	{
		file >> ch;
		if (!file) return Token(quit);
	}
	while (isspace(ch))
	{
		if (ch == '\n')
		{
			return Token(print);
		}
		cin.get(ch);
	}

	switch (ch) {
	case quit:
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':	// we need to add the comma so the parser knows hot to treat it when encountered.
		if (output_to_file) output << ch;
		return Token(ch);
	case '#':
		if (output_to_file) output << ch;
		return Token(let);
	case 'h':
	case 'H':
		if (output_to_file) output << ch;
		return Token(help);
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
		double val;
		if (using_cin)
		{
			cin.unget();
			cin >> val;
			if (!cin) error("Bad token");
		}
		else
		{
			file.unget();
			file >> val;
			if (!file) error("Bad token");
		}
		if (output_to_file) output << val;
		return Token(number, val);
	}

	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			if(using_cin)
			{
				while (cin.get(ch) && ((ch == '_') || isalpha(ch) || isdigit(ch)))	// Added underscores to var_table
					s += ch;
				cin.putback(ch);
				if (!cin) error("Bad token");
			}
			else
			{
				while (file.get(ch) && ((ch == '_') || isalpha(ch) || isdigit(ch)))
					s += ch;
				file.unget();
				if (!file) error("Bad token");
			}
			if (output_to_file) output << s;
			if (s == "let") return Token(let);
			if (s == "quit" || s == "exit") return Token(quit);
			if (s == "help") return Token(help);
			if (s == "sqrt") return Token(squrt);
			if (s == "pow") return Token(pw);
			if (s == declkey) return Token(let); // keyword "let"
			if (s == constkey) return Token(con); // keyword "const"
			if (s == "from") return Token(from_file);
			if (s == "to") return Token(to_file);
			return Token(name, s);
		}
		error("Bad token");
		return Token(' ');
	}
}

//------------------------------------------------------------------------------
// Skip characters until its argument is matched, and throw that character away.
void Token_stream::ignore(char c)
{
	if (!primary()) return;
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

//------------------------------------------------------------------------------
// The token stream.
Token_stream ts;

//------------------------------------------------------------------------------
//  This is a named variable.
class Variable {
public:
	string name;
	double value;
	bool var;		// variable (true), constant (false)
	Variable(string n, double v, bool va = true) :name(n), value(v), var(va) { }
};

//------------------------------------------------------------------------------
// Symbol Table Class
class Symbol_table {
public:
	vector<Variable> var_table;
	double get_value(string);
	void set_value(string, double);
	bool is_declared(string);
	double define_name(string, double, bool);
};

//------------------------------------------------------------------------------
//  Get the value of a variable, or fail if no match.
double Symbol_table::get_value(string s)
{
	for (size_t i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);
	return 0.0;
}

//------------------------------------------------------------------------------
//  Set the value of a variable, or fail if no match.
void Symbol_table::set_value(string s, double d)
{
	for (size_t i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s)
		{
			if (var_table[i].var == false) error(s, " is a constant");
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

//------------------------------------------------------------------------------
// Check if a variable exists.
bool Symbol_table::is_declared(string s)
{
	for (size_t i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}

//------------------------------------------------------------------------------
// Add (s,val,var) to var_table
double Symbol_table::define_name(string s, double val, bool var = true)
{
	if (is_declared(s)) error(s, " declared twice");
	var_table.push_back(Variable(s, val, var));
	return val;
}

//------------------------------------------------------------------------------
// The symbol table.
Symbol_table st;

//------------------------------------------------------------------------------
// declaration so that primary() can call expression()
double expression();

//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
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
		return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case squrt:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		ts.putback(t);
		double x = primary();
		if (x < 0.0) error("Square root of a negative number");
		return sqrt(x);
	}
	case pw:
	{
		return powerup();
	}
	case name:
	{
		Token next = ts.get();
		if (next.kind == '=')
		{
			double d = expression();
			st.set_value(t.name, d);
			return d;
		}
		else
		{
			ts.putback(next);
			return st.get_value(t.name);
		}
	}
	default:
		error("primary expected");
		return 0.0;
	}
}

//------------------------------------------------------------------------------
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
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2 == 0) error("%: divide by zero");
			left = i1 % i2;
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------
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
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------
// Read a variable declaration.
double declaration(Token k)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	st.define_name(var_name, d, k.kind == let);
	return d;
}

//------------------------------------------------------------------------------
// Read a statement.
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case con:
		return declaration(t.kind);
	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------
// Skip to the next print character.
void clean_up_mess()
{
	if (ts.primary())
		ts.ignore(print);
	else
		ts.closefile();
}

//------------------------------------------------------------------------------
// Help instructions
void help_instructions()
{
	cout << "********************************" << endl;
	cout << "*      SIMPLE CALCULATOR       *" << endl;
	cout << "********************************" << endl << endl;
	cout << "H or h or help    - This menu." << endl;
	cout << "Q or quit or exit - Quit the program." << endl;
	cout << "; or Enter        - Print output." << endl;
	cout << "# or let          - Define variable - [a-zA-Z][a-zA-Z_0-9]*" << endl;
	cout << "const             - Define constant - [a-zA-Z][a-zA-Z_0-9]*" << endl;
	cout << "sqrt(number)      - Square Root function." << endl;
	cout << "pow(number, exp)  - Power function." << endl;
	cout << "from x            - Read from file 'x'." << endl;
	cout << "to y              - Write output to file 'y'." << endl;
}

//------------------------------------------------------------------------------
// The main calculation loop.
void calculate()
{
	while (cin)
		try
		{
			cout << prompt;
			if (output_to_file)
				output << endl << ts.where() << ": " << prompt;
			Token t = ts.get();
			if (t.kind == help)
			{
				help_instructions();
			}
			else if (t.kind == from_file)
			{
				if (!ts.primary()) error("We are already reading input");
				string name = ts.readname();
				if (output_to_file) output << name << endl;
				ts.openfile(name);
			}
			else if (t.kind == to_file)
			{
				if (output_to_file) error("Output is already copied");
				string name = ts.readname();
				if (output_to_file)	output << name << endl;
				output.open(name.c_str());
				if (!output) error("Unable to open output");
				output_to_file = true;
			}
			else if (t.kind == quit) 
			{
				if (output_to_file) output << endl;
				if (ts.primary()) return;
				ts.closefile();
			}
			else
			{
				ts.putback(t);
				double res = statement();
				if (output_to_file)
					output << endl << result << res << endl;
				cout << result << res << endl;
			}
		}
		catch (runtime_error& e) 
		{
			if (output_to_file) output << endl;
			diagnose(e.what());
			clean_up_mess();
		}
		if (output_to_file) output << endl;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main()

try {
	// predefine names:
	st.define_name("pi", 3.1415926535, false);	// these predefined names are constants
	st.define_name("e", 2.7182818284, false);

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "exception \n";
	return 2;
}