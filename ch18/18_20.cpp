//@Squawk09

//Exercise 18.20
//In the following code, determine which function, if any, matches the call to compute, List the candidate and viable functions.
//What type conversions, if any, are applied to the argument to match the parameter in each viable function.

//void compute(int) first, no type conversion

//void const void works.
//void compute() doesn't work
//double double works converted to double
//char char works
#include<iostream>

namespace primerLib {
    void compute();  //Error, does not work. Too many argument in the call to match.
	void compute(const void *) { }; //Works! Converts argument to a constant void pointer.
}

void compute(int) { std::cout << "compute(int)" << std::endl; };//Works! Most closely matches the argument parameters so it is selected first.
void compute(double, double =3.4);//Works! Converts argument to double.
void compute(char* x,char* =0);//Works! converts to a character pointer.

void f()
{
	using primerLib::compute;
    compute(0);
}

int main()
{
	f();
    return 0;
}

//What would happen if using declaration were located in main before the call to compute?
//Answer the same questions as before.

//The compiler will match to void compute( const void *) in the primerLib namespace.
//void compute() will still not work because of too many arguments.
