// Jared Mathes
// 2018-08-23
// Chapter 10
// Exercise 06
// Roman numerals as int class
// See https://github.com/0p3r4t4/PPPUCPP2nd/blob/master/ch10/10.exercise.06.md

#include "../../std_lib_facilities.h"

constexpr size_t lut_end{ 100 };
constexpr int max_roman{ 4999 };			// max int representable with implemented notation
constexpr int min_roman{ 1 };				// min int

class Not_a_particle { };			// Exception when get_particle or lut_idx doesn't
									// found a particle
class Not_roman { };				// Exception when Roman_int initialized with
									// value out of [min, max]

struct lut_row
{
	string particle;				// particle of roman number
	int value;						// associated decimal value
	size_t next;					// next particle to look ahead after this particle
};

vector<lut_row> lut =				// Look up table to process Roman int in and out
{
	{"M",   1000,   1},				// Index 0
	{"M",   1000,   2},				// Index 1
	{"M",   1000,   3},				// Index 2
	{"M",   1000,   4},				// Index 3
	{"CM",  900,    11},			// Index 4
	{"D",   500,    7},				// Index 5
	{"CD",  400,    11},			// Index 6
	{"C",   100,    8},				// Index 7
	{"C",   100,    9},				// Index 8
	{"C",   100,    10},			// Index 9
	{"C",   100,    11},			// Index 10
	{"XC",  90,     18},			// Index 11
	{"L",   50,     14},			// Index 12
	{"XL",  40,     18},			// Index 13
	{"X",   10,     15},			// Index 14
	{"X",   10,     16},			// Index 15
	{"X",   10,     17},			// Index 16
	{"X",   10,     18},			// Index 17
	{"IX",  9,      25},			// Index 18
	{"V",   5,      21},			// Index 19
	{"IV",  4,      25},			// Index 20
	{"I",   1,      22},			// Index 21
	{"I",   1,      23},			// Index 22
	{"I",   1,      24},			// Index 23
	{"I",   1,      25},			// Index 24
	{"E",   0,      lut_end}		// Index 25
};

const size_t lut_size{ lut.size() };
int parse_roman(istream&);
string compose_roman(int);

class Roman_int
{
public:
	Roman_int(string s);			// Initialize with a roman numeral
	Roman_int(int a);				// Initialize with an integer

	string value() const;			// Return a string with the roman numeral representation
	int as_int() const { return m_value; }	// Return the int value

private:
	int m_value;
};

Roman_int::Roman_int(string s)
	:m_value{0}						// initialize with zero.  We parse to get actual value
{
	stringstream ss{ s };			// to be able to reuse parse_roman
	m_value = parse_roman(ss);		// could throw Not_roman

	string dummy;
	ss >> dummy;
	if (dummy.size() != 0)			// s is not totally consumed, so throw an error
	{
		throw Not_roman{};
	}
}

Roman_int::Roman_int(int a)
	:m_value{a}
{
	if (m_value < min_roman || m_value > max_roman)
	{
		throw Not_roman{};
	}
}

string Roman_int::value() const
{
	string s{ compose_roman(m_value) };
	return s;
}

size_t lut_idx(string& particle, size_t start)
{
	for (size_t i = start; i < lut_size; ++i)
	{
		if (lut[i].particle == particle)
		{
			return i;
		}
	}
	throw Not_a_particle{};
}

string get_particle(istream& is, size_t start)
{
	char first, second;
	string particle;
	
	// read two chars and compose a particle, taking into account EOF
	first = is.get();
	if (is.eof() || isspace(first))
		return "E";					// no more to read, use E as a fake end
	particle = first;

	second = is.get();
	if (is.eof())
	{
		is.clear();					// backtrack the out of bounds read
		try
		{
			lut_idx(particle, start);	// throws Not_a_particle
		}
		catch (Not_a_particle& e)
		{
			is.putback(first);		// rollback read character from input stream
			throw;					// re-throw to caller
		}
	}
	else
	{
		particle += second;
		try
		{
			lut_idx(particle, start);
		}
		catch (Not_a_particle& e)
		{
			is.putback(second);		// rollback second read character from input stream
			particle = first;
			try 
			{
				lut_idx(particle, start);
			}
			catch (Not_a_particle& e)
			{
				is.putback(first);	// rollback first read character from input stream
				throw;				// re-throw to caller
			}
		}
	}
	return particle;
}

int parse_roman(istream& is)
{
	int r{ 0 };						// accumulator
	size_t idx{ 0 };				// index to begin the search of a particle in the LUT
	while (idx != lut_end)
	{
		try
		{
			string particle = get_particle(is, idx);
			idx = lut_idx(particle, idx);
			r += lut[idx].value;
			idx = lut[idx].next;
		}
		catch (Not_a_particle& e)	// no particle has been parsed
		{
			if (r == 0)
			{
				throw Not_roman{};
				break;				// return the roman parsed so far
			}
		}
	}
	return r;
}

string compose_roman(int a)
{
	if (a<min_roman || a > max_roman)
		throw Not_roman{};

	string s{ "" };
	size_t idx{ 0 };

	while (a != 0)
	{
		if (a >= lut[idx].value)	// test if m_value can hold it
		{
			s += lut[idx].particle;
			a -= lut[idx].value;
		}
		++idx;						// next particle
	}

	return s;
}

ostream& operator<<(ostream& os, const Roman_int& rhs)
{
	os << rhs.value();
	return os;
}

istream& operator>>(istream& is, Roman_int& rhs)
{
	try 
	{
		rhs = Roman_int{ parse_roman(is) };
	}
	catch (Not_roman& e)			// on error, just set failbit on istream
	{
		is.clear(ios_base::failbit);
	}
	return is;
}

int main()
try
{
	Roman_int r{ 45 };
	cout << r.value() << endl;

	r = Roman_int{ "MCMLXXXVII" };
	cout << r << " in Roman is " << r.as_int() << " in decimal." << endl;

	// Provoke errors on constructor
	/*try {
		r = Roman_int{ "IXIX" };
		cout << r.as_int() << '\n';
	}
	catch (Not_roman& e) {
		cout << "NOT ROMAN!!\n";
	}*/
	try {
		r = Roman_int{ "abdba" };
		cout << r.as_int() << '\n';
	}
	catch (Not_roman& e) {
		cout << "NOT ROMAN!!\n";
	}

	while (cin >> r)
	{
		cout << r.as_int() << " -> " << r << endl;
	}

	return 0;
}

catch (Not_roman& e)
{
	cerr << "Tried to read something else or create a Roman_int out of bounds ["
		<< min_roman << ", " << max_roman << "]\n";
	return 1;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	return 2;
}

catch (...)
{
	cerr << "exception\n";
	return 3;
}