//
//  ex12_24.cpp
//  Exercise 12.24
//
//  Created by pezy on 12/30/14.
//
//  Write a program that reads a string from the standard input into a dynamically allocated character array.
//  Describe how your program handles varying size inputs.
//  Test your program by giving it a string of data that is longer than the array size you've allocated.


#include <iostream>

int main()
{
    // need to tell the size.
    std::cout << "How long do you want the string? ";
    int size{ 0 };
    std::cin >> size;
    char *input = new char[size+1]();
    std::cin.ignore();
    std::cout << "input the string: ";
    std::cin.get(input, size+1);
    std::cout << input;
    delete [] input;
    // Test: if longer than the array size, we will lost the characters which are out of range.
}
