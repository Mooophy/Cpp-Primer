///
///@Author  PEZY
///@Date    Aug. 2014
///@Brief
/// Read a set of integers into a vector.
/// Print the sum of each pair of adjacent elements.
/// Change your program so that it prints the sum of the first and last elements,
/// followed by the sum of the second and second-to-last, and so on.
///

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
  vector<int> ivec;
  int i;
  while (cin >> i)
    ivec.push_back(i);  

  for(decltype(ivec.size()) i=0; i!=ivec.size()-1; ++i)
    cout << ivec[i] + ivec[i+1] << " ";
  cout << endl;

  decltype(ivec.size()) size = ivec.size();
  if (size%2 != 0) size = size/2 + 1;
  else size /= 2;

  for(decltype(ivec.size()) i=0; i!=size; ++i)
    cout << ivec[i] + ivec[ivec.size()-i-1] << " ";
  cout << endl;  

  return 0;
}

///
///@Output
///1 2 3 4 5 6 7 8 9 10
///EOF
///3 5 7 9 11 13 15 17 19
///11 11 11 11 11
///
