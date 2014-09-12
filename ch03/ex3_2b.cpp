// read the standard input a word at a time
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
  string word;
  while (cin >> word)
    cout << word << endl;

  return 0;
}
