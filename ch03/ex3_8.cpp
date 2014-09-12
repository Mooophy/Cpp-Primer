//Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
  string str("a simple string");
  // use while
  decltype(str.size()) i = 0;
  while (i < str.size())
  {
    str[i] = 'X';
    ++i;
  }
  cout << str << endl;

  // use traditional for
  for (i=0; i<str.size(); ++i)
    str[i] = 'Y';
  cout << str << endl;

  // I like the first one.
  return 0;
}
