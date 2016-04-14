//
//  ex12_26.cpp
//  Exercise 12.26 
//
//  Created by pezy on 12/30/14.
//
//  Rewrite the program on page 481 using an allocator. 

#include <iostream>
#include <string>
#include <memory>

void input_reverse_output_string(int n)
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while (q != p + n && std::cin >> s)
        alloc.construct(q++, s);
    
    while (q != p)
    {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}

int main()
{
    input_reverse_output_string(5);
}
