/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       7  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 17.28:
//! Write a function that generates and returns a uniformly distributed random
//! unsigned int each time it is called.
//!
//! Exercise 17.29:
//! Allow the user to supply a seed as an optional argument to the function you
//! wrote in the previous exercise.
//!
//! Exercise 17.30:
//! Revise your function again this time to take a minimum and maximum value for
//! the numbers that the function should return.
//!

#include <iostream>
#include <random>

//! default version
unsigned random_gen();
//! with seed spicified
unsigned random_gen(unsigned seed);
//! with seed and range spicified
unsigned random_gen(unsigned seed, unsigned min, unsigned max);
int main()
{
    std::string temp;
    while(std::cin >> temp)
    std::cout << std::hex << random_gen(19,1,10) << std::endl;
    return 0;
}

unsigned random_gen()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

unsigned random_gen(unsigned seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

unsigned random_gen(unsigned seed, unsigned min, unsigned max)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud(min,max);
    return ud(e);
}
