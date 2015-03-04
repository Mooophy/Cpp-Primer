//! @Alan
//!
//! Exercise 6.21:
//! Write a function that takes an int and a pointer to an int and
//! returns the larger of the int value or the value to which the
//! pointer points. What type should you use for the pointer?
//!

#include <iostream>
using std::cout; 

int LargerOne(const int i, const int *ip)
{
    return (i > *ip) ? i : *ip;
}

int main()
{
    int c = 6;
    cout << LargerOne(7, &c);

    return 0;
}


