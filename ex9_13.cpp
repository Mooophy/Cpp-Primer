//! @Alan
//!
//! Exercise 9.13:
//! How would you initialize a vector<double> from a list<int>?
//! From a vector<int>?
//! Write code to check your answers.
//!
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>


int main()
{
    std::list<int> ls(10,1);
    std::vector<int> vi(10,2);

    std::vector<double> v(vi.begin(),   vi.end());
    return 0;
}
