#include <iostream>
#include <vector>
#include <iterator>

using std::vector; using std::cout; using std::endl; using std::cin;

int main()
{
  int i;
  vector<int> ivec;
  while (cin >> i)
    ivec.push_back(i);

  if (ivec.empty())
  {
    cout << "input at least one integer." << endl;
    return -1;
  }
  else if(ivec.size() == 1)
  {
    cout << *ivec.begin() << " has no adjacent elements.";
  }
  
  for (auto it = ivec.begin(); it+1 != ivec.end(); ++it)
    cout << *it + *(it+1) << " ";
  cout << endl;

  for (auto beg = ivec.begin(), end = ivec.end()-1; beg <= end; ++beg, --end)
    cout << *beg + *end << " ";
  cout << endl;

  return 0;
}
