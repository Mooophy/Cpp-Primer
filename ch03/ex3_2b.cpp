// read the standard input a word at a time
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    for (string str; cin >> str; cout << str << endl);
    return 0;
}
