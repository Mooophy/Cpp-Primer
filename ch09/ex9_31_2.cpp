//
//  ex9_31.cpp
//  Exercise 9.31 
//
//  Created by pezy on 12/3/14.
//
//  @Brief  The program on page 354 to remove even-valued elements and 
//          duplicate odd ones will not work on a list or forward_list. Why? 
//          Revise the program so that it works on these types as well. 
//  @forward_list   1. vi.insert -> vi.insert_after
//                  2. iter += 2; -> advance(iter, 2);
//                  3. vi.erase -> vi.erase_after
//                  4. added iterator prev, and edit some detail

#include <iostream>
#include <forward_list>

using std::forward_list; using std::cout; using std::endl; using std::advance;

int main()
{
    forward_list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter = vi.begin(), prev = vi.before_begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert_after(prev, *iter);
            advance(iter, 2);
            advance(prev, 2);
        }
        else
            iter = vi.erase_after(prev);
    }

    for (auto i : vi)
        cout << i << " ";

    return 0;
}
