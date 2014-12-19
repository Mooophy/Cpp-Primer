/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       22  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.6:
//! Write a function that returns a dynamically allocated vector of ints.
//! Pass that vector to another function that reads the standard input to
//! give values to the elements. Pass the vector to another function to print
//! the values that were read.
//! Remember to delete the vector at the appropriate time.
//!

#include <iostream>
#include <vector>
#include <string>
#include <memory>

std::vector<int>*
dynamic_vector_generator();

void
dynamic_vector_processor(std::vector<int>* ptr_v);

void
dynamic_vector_printer(std::vector<int>* ptr_v);

int main()
{
    /**
      * testing the 3 functions
      */
    std::vector<int>* ptr_vi = dynamic_vector_generator();
    dynamic_vector_processor(ptr_vi);
    dynamic_vector_printer(ptr_vi);

    delete ptr_vi;


    return 0;
}

/**
 *  @brief  return a pointer to dynamicly allocated vector of ints
 */
std::vector<int> *
dynamic_vector_generator()
{
    std::vector<int>* ptr_v = new std::vector<int>();
    return ptr_v;
}

/**
 * @brief return a pointer to vector of ints
 * @param ptr_v pointer to vector of ints
 */
void dynamic_vector_processor(std::vector<int> *ptr_v)
{
    int i;
    std::cout << "plz enter:\n";
    while(std::cin >>i && i != 999)
        ptr_v->push_back(i);

}

/**
 * @brief print the content of the vector that ptr_v points to
 * @param ptr_v
 */
void dynamic_vector_printer(std::vector<int> *ptr_v)
{
    for(const auto &e : *ptr_v)
        std::cout << e << " ";
    std::cout << "\n";
}
