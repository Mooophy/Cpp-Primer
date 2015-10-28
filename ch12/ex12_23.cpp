//
//  ex12_23.cpp
//  Exercise 12.23 
//
//  Created by pezy on 12/30/14.
//
//  Write a program to concatenate two string literals, putting the result in a dynamically allocated array of char. 
//  Write a program to concatenate two library strings that have the same value as the literals used in the first program. 

#include <iostream>
#include <string>
#include <string.h>

int main()
{
    // dynamically allocated array of char
    char *concatenate_string = new char[strlen("hello " "world") + 1]();
    strcat(concatenate_string, "hello ");
    strcat(concatenate_string, "world");
    std::cout << concatenate_string << std::endl;
    delete [] concatenate_string;
    
    // std::string
    std::string str1{ "hello " }, str2{ "world" };
    char *concatenate_string2 = new char[str1.length() + str2.length() + 1]();
    strcpy(concatenate_string2, (str1+str2).c_str());
    std::cout << concatenate_string2 << std::endl;
}
