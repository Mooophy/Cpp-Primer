//
//  ex9_31.cpp
//  Exercise 9.31 
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  The program on page 354 to remove even-valued elements and 
//          duplicate odd ones will not work on a list or forward_list. Why? 
//          Revise the program so that it works on these types as well. 
//  @list   iter += 2; -> advance(iter, 2);
//

#include <iostream>
#include <list>

using std::list; using std::cout; using std::endl; using std::advance;

int main()
{
    list<int> vi = {0,1,2,3,4,5,6,7,8,9}; 
    auto iter = vi.begin(); 
    while (iter != vi.end()) {    
        if (*iter % 2) {        
            iter = vi.insert(iter, *iter);  
            advance(iter, 2); 
        } else        
            iter = vi.erase(iter); 
    }
    
    for (auto i : vi)
        cout << i << " ";
    
    return 0;
}


