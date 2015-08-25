//
//@Author  @PEZY       @Yue Wang   
//@Date    Aug. 2014   Jun. 2015
//@Brief
// List three ways to define a vector and give it ten elements,
// each with the value 42.
// Indicate whether there is a preferred way to do so and why.

#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec1(10, 42);
    vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
    vector<int> ivec3;
    for (int i = 0; i != 10; ++i) ivec3.push_back(42);
    std::cout << "The first approach is better!" << std::endl;

    return 0;
}
