//! @Alan
//!
//! Exercise 9.50:
//! Write a program to process a vector<string>s whose elements represent integral values.
//! Produce the sum of all the elements in that vector.
//! Change the program so that it sums of strings that represent floating-point values.
//!

#include <iostream>
#include <string>
#include <vector>


int sum(const std::vector<std::string> &v);
float sum_f(const std::vector<std::string> &v);

int main()
{
    std::vector<std::string> v = {"1","2","3","4.5"};
    std::cout << sum(v)<<"\n";
    std::cout << sum_f(v);
    return 0;
}


int sum(const std::vector<std::string> &v)
{
    int sum=0;
    for(auto &s : v)
    {
        sum += std::stoi(s);
    }

    return sum;
}


float sum_f(const std::vector<std::string> &v)
{
    float sum = 0.0;
    for(auto &s : v)
    {
        sum += std::stof(s);
    }
    return sum;
}
