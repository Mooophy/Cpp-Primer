///
///Write a program to create a vector with ten int elements. 
///Using an iterator, assign each element a value that is twice its current value.
/// Test your program by printing the vector.
///

#include <vector>
#include <iostream>
#include <iterator>

using std::vector; using std::iterator; using std::cout; using std::endl;

int main()
{
  vector<int> ivec(10, 1);
  for (auto it = ivec.begin(); it != ivec.end(); ++it)
    *it *= 2;
  for (auto value : ivec)
    cout << value << " ";
  cout << endl;

  return 0;
}
