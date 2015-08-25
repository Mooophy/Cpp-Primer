//@Yue wang
//
// Exercise 6.10:
// Using pointers, write a function to swap the values of two ints.
// Test the function by calling it and printing the swapped values.
//
#include <iostream>
#include <string>
#include <stdexcept>


void swap(int* lhs, int* rhs)
{
    int tmp;
    tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

int main()
{
    for (int lft, rht; std::cout << "Please Enter:\n", std::cin >> lft >> rht; )
    {
        swap(&lft, &rht);
        std::cout << lft << " " << rht << std::endl;
    }

    return 0;
}
