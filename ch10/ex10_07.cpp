//
//  ex10_07.cpp
//  Exercise 10.7
//
//  Created by pezy on 12/9/14.
//
//  @Brief  Determine if there are any errors in the following programs and, if so, correct the error(s)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector; using std::cout; using std::endl; using std::list; using std::cin; using std::fill_n;

template<typename Sequence>
void print(Sequence const& seq)
{
    for (const auto& i : seq)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // (a)
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    vec.resize(lst.size());
    // ^ Fixed: added this statement
    // Cause Algorithms that write to a destination iterator assume
    // the destination is large enough to hold the number of elements being written.
    copy(lst.cbegin(), lst.cend(), vec.begin());
    
    // (b)
    vector<int> v;
    v.reserve(10);
    fill_n(v.begin(), 10, 0);
    // ^ (b)No error, but not any sense. v.size() still equal zero.
    // Fixed: 1. use `v.resize(10);`
    //    or  2. use `fill_n(std::back_inserter(v), 10, 0)`
    
    print(v);
    print(vec);
}
