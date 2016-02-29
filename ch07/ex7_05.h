//
//  ex7_05.h
//  Exercise 7.5
//
//  Created by pezy on 14/11/8.
//
//  Revised by @Yue Wang Jun 2015:
//
//  1. add public access modifier for the function members
//  2. use trailing return type 
//

#ifndef CP5_ex7_05_h
#define CP5_ex7_05_h

#include <string>

class Person 
{
    std::string name;
    std::string address;
public:
    auto get_name() const -> std::string { return name; }
    auto get_addr() const -> std::string { return address; }
};

#endif
