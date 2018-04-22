//read strings from the standard input, concatenating what is read into one large string. 
//Print the concatenated string.
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string concatenated, buffer;
  while (cin >> buffer) {
    concatenated += buffer;
    cout << "The concatenated string is " << concatenated << endl;
  }

  return 0;
}
