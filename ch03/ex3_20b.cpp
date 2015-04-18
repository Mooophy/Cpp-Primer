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
  
  if (ivec.empty())
  {
    cout << "input at least one integer." << endl;
    return -1;
  }
  decltype(ivec.size()) size = ivec.size();
  if (size%2 != 0) size = size/2 + 1;
  else size /= 2;

  for(decltype(size) i = 0; i != size; ++i)
    cout << ivec[i] + ivec[ivec.size()-i-1] << " ";
  cout << endl;  

  return 0;
}
