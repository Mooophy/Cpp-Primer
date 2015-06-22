//! @Yue Wang
//!
//! Exercise 6.22:
//! Write a function to swap two int pointers.
//!
#include <iostream>

void swap(int*& lft, int*& rht)
{
    auto tmp = lft;
    lft = rht;
    rht = tmp;
}

int main()
{
    int i = 42, j = 99;
    auto lft = &i;
    auto rht = &j;
    swap(lft, rht);
    std::cout << *lft << " " << *rht << std::endl;

    return 0;
}
