/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.6:
//! What is a copy-assignment operator? When is this operator used? What does
//! the synthesized copy-assignment operator do? When is it synthesized?
//  A copy-assignment operator is an overloaded operator which controls how
//  objects of its class are assigned.
//  The compiler generates a synthesized copy-assignment operator if no user-
//  defined version is provided.
//  Analogously to the copy constructor, for some classes the synthesized copy-
//  assignment operator disallows assignment (§ 13.1.6, p. 508). Otherwise, it
//  assigns each nonstatic member of the right-hand object to the corresponding
//  member of the left-hand object using the copy-assignment operator for the
//  type of that member. Array members are assigned by assigning each element
//  of the array. The synthesized copy-assignment operator returns a reference
//  to its left-hand object.
//!
//! Exercise 13.7:
//! What happens when we assign one StrBlob to another? What about StrBlobPtrs?
//  In both cases, shallow copy will happen. All pointers point to the same address.
//!
//! Exercise 13.8:
//! Write the assignment operator for the HasPtr class from exercise 13.5 in
//! § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should
//! copy the object to which ps points.
//!

#include <string>
#include <iostream>

class HasPtr
{
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    //! copy constructor.
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }

    /**
     * @brief operator =    Copy-Assignment operator
     */
    //! return reference to the class
    HasPtr&
    operator = (const HasPtr& hp)
    {       //!^^^^^^^^^^^^^^^^^^ right hand side explicit
        *ps = *hp.ps;
        i   = hp.i;
        return *this;
            //!^^^^^^   return *this .
            //! When an operator is a member function, the left-hand operand
            //! is bound to the implicit "this" parameter .
    }

private:
    std::string *ps;
    int    i;
};

int main()
{
    HasPtr hp("sss");
    HasPtr hp2 = hp;


    return 0;
}

