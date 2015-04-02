/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#include <iostream>

void factorial_with_interacts() {
    int num;
    std::cout << "Please input a positive number: ";
    while ( std::cin >> num && num < 0 )
        std::cout << "Please input a positive number again: ";
    std::cout << num;

    unsigned long long result = 1;
    while (num > 1) result *= num--;

    std::cout << "! is ";
    if ( result ) std::cout << result << std::endl;
    else std::cout << "too big" << std::endl;
}

int main()
{
    factorial_with_interacts();
}
