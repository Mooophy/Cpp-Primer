//separate adjacent input strings by a space.
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string str, buffer;
  while (cin >> buffer) {
    str += (str.empty() ? "" : " ") + buffer;
    cout << "The concatenated string is " << str << endl;
  }

  return 0;
}
