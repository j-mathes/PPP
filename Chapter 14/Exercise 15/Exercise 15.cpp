//----------------------------------------------------------------------------
// File:	Exercise 15.cpp
// Date:	2019-01-13
// Author:	Jared
//----------------------------------------------------------------------------
// Solution:Chapter 14
// Project:	Exercise 15
//----------------------------------------------------------------------------
// Description: Iterator class
//----------------------------------------------------------------------------

#include "../../std_lib_facilities.h"

namespace Exercise_14_15
{
	class Iterator
	{
	public:
		virtual double* next() = 0;

	protected:
		int p;
	};
	
	class Vector_iterator : public Iterator
	{
	public:
		Vector_iterator(const vector<double>& vv)
			: v(vv)
		{
			p = 0;
		}
		double* next();
	private:
		vector<double> v;
	};

	double* Vector_iterator::next()
	{
		if (v.size() && v.size() > p)
		{
			++p;
			return &v[p - 1];
		}
		else return 0;
	}

	class List_iterator : public Iterator
	{
	public:
		List_iterator(const list<double>& ll)
			:l(ll)
		{
			ptr = l.begin();
		}
		double* next();
	private:
		list<double> l;
		list<double>::iterator ptr;
	};

	double* List_iterator::next()
	{
		double* p;
		if (l.size() && l.size() > distance(l.begin(),ptr))
		{
			p = &*ptr;
			++ptr;
			return p;
		}
		else return 0;
	}

	void print(Iterator& it)
	{
		double* p;
		p = it.next();
		while (p != 0)
		{
			cout << *p << endl;
			p = it.next();
		}
	}
}


//----------------------------------------------------------------------------
// main
//----------------------------------------------------------------------------
int main()
try
{
	vector<double> vec;

	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}

	Exercise_14_15::Vector_iterator vi(vec);
	Exercise_14_15::print(vi);

	list<double> l;
	l.push_back(1.2);
	l.push_back(2.3);
	l.push_back(3.4);
	l.push_back(4.5);

	Exercise_14_15::List_iterator li(l);
	Exercise_14_15::print(li);

	return 0;
}

catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
}

catch (...)
{
	cerr << "exception\n";
}