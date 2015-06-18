// Print each number in the range specified by two integers.

#include <iostream>

int main()
{
    int small = 0, big = 0;
    std::cout << "please input two integers:\n";
    std::cin >> small >> big;
    if (small > big) 
        std::swap(small, big);

    for (int curr = small; curr != big; ++curr) 
        std::cout << curr;

    return 0;
}
