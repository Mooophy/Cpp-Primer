/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       3  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.65:
// In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one
// had a const char* and the other a char* parameter. Rewrite these functions
// as specializations.
//
// Exercise 16.66:
// What are the advantages and disadvantages of overloading
// these debug_rep functions as compared to defining specializations?
//
//  Overloading changes the function match.
//
// Exercise 16.67:
// Would defining these specializations affect function matching for debug_rep?
// If so, how? If not, why not?
//
//  Won't change.
//  Specializations instantiate a template; they do not overload it. As a result,
//  specializations do not affect function matching.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

// template
template <typename T>
std::string debug_rep(T* t);

// template specialization T=const char*  ,  char*  respectively.
template<>
std::string debug_rep(const char* str);
template<>
std::string debug_rep(      char *str);

int main()
{
    char p[] = "alan";
    std::cout << debug_rep(p) << "\n";
    return 0;
}


template <typename T>
std::string debug_rep(T* t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// template specialization
// T = const char*
template<>
std::string debug_rep(const char* str)
{
    std::string ret(str);
    return str;
}

// template specialization
// T =       char*
template<>
std::string debug_rep(      char *str)
{
    std::string ret(str);
    return ret;
}
