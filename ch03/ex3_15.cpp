///
///@Author  PEZY
///@Date    Aug. 2014
///@Brief
/// read a sequence of strings from cin and
/// store those values in a vector.
///

#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> vec;
  std::string str;
  while (std::cin >> str)
    vec.push_back(str);

  return 0;
}
