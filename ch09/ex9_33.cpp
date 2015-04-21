//
//  ex9_33.cpp
//  Exercise 9.33 
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the final example in this section what would happen 
//          if we did not assign the result of insert to begin? 
//          Write a program that omits this assignment to see if your expectation was correct.  
//  @Answer crash, cause the iterator is invalid after insert. Because Iterators, pointers, and references to a
//          vector or string are invalid if the container was reallocated. 

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9}; 
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;
        /*begin = */v.insert(begin, 42);
        ++begin;
    } 
    
    for (auto i : v)
        cout << i << " ";
    
    return 0;
}


