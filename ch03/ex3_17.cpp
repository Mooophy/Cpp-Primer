///
///@Author  PEZY
///@Date    Aug. 2014
///@Brief
/// Read a sequence of words from cin and store the values a vector.
/// After you've read all the words, process the vector and change each word to uppercase. 
/// Print the transformed elements, eight words to a line.
///

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
  vector<string> vec;
  string word;
  while (cin >> word)
    vec.push_back(word);

  for (auto &str : vec)
    for (auto &c : str)
      c = toupper(c);

  for (decltype(vec.size()) i=0; i != vec.size(); ++i)
  {
    if (i != 0 && i%8 == 0) cout << endl;
    cout << vec[i] << " ";
  }
  cout << endl;

  return 0;
}

///
///@Output
///pezy is a good programmer you can ask any question to him all the time he is playing the codes
///^D(EOF)
///PEZY IS A GOOD PROGRAMMER YOU CAN ASK
///ANY QUESTION TO HIM ALL THE TIME HE
///IS PLAYING THE CODES
///
