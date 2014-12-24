/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       23  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.12:
//! Using the declarations of p and sp explain each of the following calls to
//! process. If the call is legal, explain what it does. If the call is illegal,
//! explain why:
//  See comments below.
//!


#include <iostream>
#include <vector>
#include <string>
#include <memory>


void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
    auto p = new int();
    auto sp = std::make_shared<int>();

    /** @brief
     *  legal. Just copy sp which is a shared_ptr to process().
     */
    //process(sp);

    /** @brief
     *  illegale.plain pointer can not convert to smart pointer implicitly.
     */
    //process(new int());

    /** @brief
     *  illegale.plain pointer can not convert to smart pointer implicitly.
     */
    //process(p);

    /** @brief
     *  Legal. A shared_ptr is construct first using plain pointer p.
     *  Afterwards,this shared_ptr is copied into the parameter of process().
     */
    //process(std::shared_ptr<int>(p));


    return 0;
}
