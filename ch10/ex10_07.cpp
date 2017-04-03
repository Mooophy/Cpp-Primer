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

    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
    // Fixed: the vec.begin() was replaced by a back_inserter iterator, capable of
    // insert new elements automatically at the end of the container.
    
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
