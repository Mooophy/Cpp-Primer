/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       11  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 18.1:
//! What is the type of the exception object in the following throws?
//!     (a) range_error r("error");
//!         throw r;
//!     (b) exception *p = &r;
//!         throw *p;
//  the static, compile-time type of that expression determines the type of
//  the exception object.
//  so the object thrown the second time is std::exception type not std::range_error.
//! What would happen if the throw in (b) were written as throw p?
//  terminate called after throwing an instance of 'std::exception*'
//!
//! Exercise 18.2: Explain what happens if an exception occurs at the indicated point:
/*
void exercise(int *b, int *e)
{
    vector<int> v(b, e);            // the object v will be destroyed by its destructor.
    int *p = new int[v.size()];     // the dynamically allocated int array will be no way deallocated.
    ifstream in("ints");            // the object in will be destroyed.
    // exception occurs here
}
*/
//! Exercise 18.3:
//! There are two ways to make the previous code work correctly
//! if an exception is thrown. Describe them and implement them.
//  The first approach is to mange it using a class. The second one is using smart pointer.
//!

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
#include<fstream>
/**
 * @brief The intArray class manage a dynamicly allocated int array.
 * @note  for ex18.3 approach 1.
 */
struct intArray
{
    intArray() : p(nullptr) {}
    explicit    intArray(std::size_t s):
        p(new int[s])       {}


    ~intArray()
    {
        delete[] p;
    }

    //! data meber
    int *p;
};

void exercise(int *b, int *e)
{
    std::vector<int> v(b, e);            // the object v will be destroyed by its destructor.

    //! @oldcode:
    //int *p = new int[v.size()];     // the dynamically allocated int array will be no way deallocated.

    //! approach 1:
    intArray p(v.size());

    //! approach 2:
    //std::shared_ptr<int> p(new int[v.size()], [](int *p) { delete[] p; });
                                                // delete array using lambda

    std::ifstream in("ints");            // the object in will be destroyed.
    // exception occurs here
}

int main()
{
    //! for ex18.1
    /*
    std::range_error r("error");
    //throw r;

    std::exception *p = &r;
    throw p;
    */
    return 0;
}
