//! @Alan
//!
//! Exercise 6.21:
//! Write a function that takes an int and a pointer to an int and
//! returns the larger of the int value or the value to which the
//! pointer points. What type should you use for the pointer?
//!



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LargerOne(const int _i,const int* _ip);


int main()
{
    int c=6;
    cout<<LargerOne(7,&c);


    return 0;
}


int LargerOne(const int _i, const int *_ip)
{
    return (_i > *_ip) ? _i : *_ip;
}
