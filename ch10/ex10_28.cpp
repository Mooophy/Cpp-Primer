//
//  ex10_28.cpp
//  Exercise 10.28
//
//  Created by pezy on 12/13/14.
//
//  Copy a vector that holds the values from 1 to 9 inclusive, into three other containers.
//  Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers.
//  Predict how the output sequence varies by the kind of inserter and verify your predictions
//  by running your programs.


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using std::list; using std::copy; using std::cout; using std::endl;

template<typename Sequence>
void print(Sequence const& seq)
{
    for (const auto& i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    // uses inserter
    list<int> lst1;
    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));
    print(lst1);
    
    // uses back_inserter
    list<int> lit2;
    copy(vec.cbegin(), vec.cend(), back_inserter(lit2));
    print(lit2);
    
    // uses front_inserter
    list<int> lst3;
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
    print(lst3);
}
