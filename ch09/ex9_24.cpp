// @Yue Wang @pezy
//
// Exercise 9.24:
// Write a program that fetches the first element in a vector using at,
// the subscript operator, front, and begin. Test your program on an empty vector.
//
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    std::cout << v.at(0);       // terminating with uncaught exception of type std::out_of_range
    std::cout << v[0];          // Segmentation fault: 11
    std::cout << v.front();     // Segmentation fault: 11
    std::cout << *v.begin();    // Segmentation fault: 11
    return 0;
}
