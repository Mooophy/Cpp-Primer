//
//  ex9_32.cpp
//  Exercise 9.32 
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the program onpage 354 would it be legal to write the call to insert as follows? 
//          If not, why not?
//          iter = vi.insert(iter, *iter++); 
//  @Answer - If only changed this, it's illegal obviously. like @Mooophy said:
//          "*iter++  can result in deferencing an item out of range causing a runtime error."
//          - If change "iter += 2;" to "++iter;" after the call. It is legal.(follow codes)

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9}; 
    auto iter = vi.begin(); 
    while (iter != vi.end()) {    
        if (*iter % 2) {        
            iter = vi.insert(iter, *iter++);  
            ++iter;
        } else        
            iter = vi.erase(iter); 
    }
    
    for (auto i : vi)
        cout << i << " ";
    
    return 0;
}


