// @Yue Wang
//
// Exercise 6.21:
// Write a function that takes an int and a pointer to an int and
// returns the larger of the int value or the value to which the
// pointer points. What type should you use for the pointer?
//

#include <iostream>
using std::cout;

int larger_one(const int i, const int *p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int i = 6;
    cout << larger_one(7, &i);

    return 0;
}
