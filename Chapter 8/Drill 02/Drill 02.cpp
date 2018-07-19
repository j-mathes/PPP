#include"../../std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp; 
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp; 
	temp = a; 
	a = b; 
	b = temp;
}

//void swap_cr(const int& a, const int& b)
//{
//	int temp; 
//	temp = a;
//	a = b;		// cannot assign because a is a constant
//	b = temp;	// cannot assign because b is a constant
//}