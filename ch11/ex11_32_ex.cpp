///@Author pezy
///
///Exercise 11.32:
///Using the multimap from the previous exercise, write a program to
///print the list of authors and their works alphabetically.
///

#include <iostream>
#include <map>
#include <set>
#include <string>

using std::string;
using std::multimap;
using std::cout;
using std::endl;
using std::multiset;

int main()
{
  multimap<string, string> map
  {
    {"alan", "google"},
    {"pezy", "player"},
    {"alan", "bible"},
    {"wang", "oh sky"},
    {"pezy", "is a programmer"},
    {"wang", "sky"}
  };

  for (auto it=map.begin(); it != map.end(); it=map.upper_bound(it->first))
  {
    cout << it->first << ":";
    multiset<string> set;
    for (auto ibeg=it; ibeg != map.upper_bound(it->first); ++ibeg)
      set.insert(ibeg->second);
    for (auto sbeg=set.begin(); sbeg != set.end(); ++sbeg)
      cout << *sbeg << " ";
    cout << endl;
  }
 
  return 0;
}

///
///output:
///alan:bible google
///pezy:is a programmer player
///wang:oh sky sky
///
