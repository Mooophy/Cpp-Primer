/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       23  DEC 2013
 *  @remark
 ***************************************************************************/
//
// Exercise 12.11:
// What would happen if we called process as follows?
//  An error was generated at run time : double free or corruption.
//  See the comments below.

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
    std::shared_ptr<int> p(new int(42));
    /**
     * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
     *          to the parameter.However it is not a copy of p. As a result, at end of this
     *          main function p will free the memory that has been freed inside process ().
     *          That's why "double freed or corruption" was generated.
     */
    process(std::shared_ptr<int>(p.get()));
    return 0;
}
