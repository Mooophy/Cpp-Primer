///
///@Author  PEZY
///@Date    Aug. 2014
///@Brief 
/// print the size and contents of the vectors from exercise 3.13.
/// Check whether your answers to that exercise were correct. 
/// If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.
///

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void check(const vector<int>& vec){
  cout << "{\"size\":\"" << vec.size() << "\",\"value\":[";
  for (auto i : vec)
    cout << i << ",";
  if (!vec.empty()) cout << "\b";
  cout << "]}" << endl;
}

void check(const vector<string>& vec){
  cout << "{\"size\":\"" << vec.size() << "\",\"value\":[";
  for (auto i : vec)
    cout << i << ",";
  if (!vec.empty()) cout << "\b";
  cout << "]}" << endl;
}

int main()
{
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 42);
  vector<int> v4{10};
  vector<int> v5{10, 42};
  vector<string> v6{10};
  vector<string> v7{10, "hi"};

  check(v1);
  check(v2);
  check(v3);
  check(v4);
  check(v5);
  check(v6);
  check(v7);
  return 0;
}

