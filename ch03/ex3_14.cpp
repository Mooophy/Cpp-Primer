///
///@Author  PEZY
///@Date    Aug. 2014
///@Brief
/// read a sequence of ints from cin and
/// store those values in a vector.
///

#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  int i;
  while (std::cin >> i)
    vec.push_back(i);

  return 0;
}
