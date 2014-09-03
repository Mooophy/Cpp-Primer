///
///Revise the loop that printed the first paragraph in text 
///to instead change the elements in text that correspond 
///to the first paragraph to all uppercase. 
///After you’ve updated text, print its contents.
///

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::vector; using std::string; using std::cout; using std::cin; using std::endl;

int main()
{
  vector<string> vec;
  string str;
  while (getline(cin, str))
    if (!str.empty()) vec.push_back(str);
  
  auto first = vec.begin();
  for (auto& c : *first)
    c = toupper(c);

  for (auto it = vec.begin(); it != vec.end(); ++it)
    cout << *it << endl;      

  return 0;
}
