//! @Alan
//!
//! Exercise 9.24:
//! Write a program that fetches the first element in a vector using at,
//! the subscript operator, front, and begin. Test your program on an empty vector.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>


int main()
{
    std::vector<int> v;
    std::cout
                //<< v.at(0);   //an exception was thrown
                    //<< v[0];                  //nothing happened
                        //<<  v.front();        //nothing happened
                            << *v.begin();      //nothing happened
    return 0;
}
