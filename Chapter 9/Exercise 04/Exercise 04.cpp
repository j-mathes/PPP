// Jared Mathes
// 2018-08-04
// Chapter 9
// Exercise 04
// Organizing code

// dangerously ugly code

// global definition of struct X
struct X 
{
	// member function f declared
	// takes an int as a parameter and returns nothing
	void f(int x) 
	{
		// locally defined struct Y defined
		struct Y 
		{
			// locally defined function f defined
			// takes no parameters, always returns 1
			int f() 
			{ 
				return 1; 
			} 
			// locally defined to struct Y integer variable m declared 
			int m;
		};
		
		// local to function f defined integer m declared
		int m;

		// m is equal to the x parameter passed to the f function
		m = x; 
		
		// struct m2 of type Y declared
		Y m2;
		
		// returning function f of struct y of a recursive call to function f of struct x
		return f(m2.f());
	}
	
	// member integer variable m declared
	int m; 
	
	// member function g declared
	// takes an int as a parameter and returns nothing
	void g(int m) 
	{
		// if parameter m is defined, call function f of struct X and pass m + 2 as parameter
		if (m) 
			f(m + 2); 
		else 
		{
			// if not m, then recursive call of parameter m + 2
			g(m + 2);
		}
	}

	// default constructor for X struct.
	X() 
	{ 
	} 
	
	// member function m3 that does nothing
	void m3() 
	{
	}

	// member function called main
	// dangerous because it looks like the main function in a program
	void main() 
	{
		// declare a struct of type X and name it a
		X a;
		
		// call function f of struct a and pass in a parameter 2
		a.f(2);
	}
};