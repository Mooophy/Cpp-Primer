/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       22  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.8:
//! Explain what if anything is wrong with the following function.
bool b()
{
    int* p = new int;
    // ...
    return p;
}
//!
//  The p will convert to a bool ,which means that the dynamic memory allocated has no
//  chance to be freed. As a result, memory leakage will occur.
//!
//! Exercise 12.9:
//! Explain what happens in the following code:
//  shown in the main function.
//!

#include <iostream>
#include <vector>
#include <string>
#include <memory>



int main()
{
    /**
     * @brief   Memory leakage happens.
     *          Because after r = q was executed, no pointer points to the int r had pointed to.
     *          It implies that no chance to free the memory for it.
     */
    int *q = new int(42), *r = new int(100);
    r = q;

    /**
     * @brief   no memory leakages.
     *          As r2 = q2 was excuted, the count of the object r2 had pointer to went to 0, which
     *          freed the correspoinding memory.
     */
    auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
    r2 = q2;

    return 0;
}
