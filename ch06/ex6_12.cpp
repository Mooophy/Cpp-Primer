//@Yue Wang
//
// Exercise 6.12:
// Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use
// references instead of pointers to swap the value of two ints. Which
// version do you think would be easier to use and why?
//  The version using reference is easier.
//
#include <iostream>
#include <string>


void swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    for (int left, right; std::cout << "Please Enter:\n", std::cin >> left >> right; )
    {
        swap(left, right);
        std::cout << left << " " << right << std::endl;
    }

    return 0;
}
