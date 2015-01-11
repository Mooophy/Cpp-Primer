//
//  ex9_32.cpp
//  Exercise 9.32
//
//  Created by pezy on 12/3/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  @Brief  In the program on page 354 would it be legal to write the call to insert as follows?
//          If not, why not?
//          iter = vi.insert(iter, *iter++);
//  @Answer the statement is illegal, cause as said in Standard [5.2.2] :
//          "The order of evaluation of arguments is unspecified."
//          As a result, after entering function insert,
//          iter could be its original value or original value + 1 or even anything else,
//          depending on how compiler implemented.
//          correct it as follows:
//  @Discuss    https://github.com/Mooophy/Cpp-Primer/issues/125

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else
            iter = vi.erase(iter);
    }

    for (auto i : vi)
        cout << i << " ";

    return 0;
}
