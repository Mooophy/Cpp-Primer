//read strings from the standard input, concatenating what is read into one large string. 
//Print the concatenated string.
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  string largeStr;
  string str;
  while (cin >> str)
  {
    largeStr += str;
  }

  cout << "The concatenated string is " << largeStr << endl;

  return 0;
}
