//
//Write a program to create a vector with ten int elements. 
//Using an iterator, assign each element a value that is twice its current value.
// Test your program by printing the vector.
//

#include <vector>
#include <iostream>
#include <iterator>

using std::vector; using std::iterator; using std::cout;

int main()
{
    vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto it = v.begin(); it != v.end(); ++it) *it *= 2;
    for (auto i : v) cout << i << " ";

    return 0;
}
