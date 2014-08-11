/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark
 ***************************************************************************/
//! Exercise 13.1:
//! What is a copy constructor? When is it used?
//  A constructor is the copy constructor if its first parameter is a reference
//  to the class type and any additional parameters have default values:
class Foo
{
public:
   Foo();             // default constructor
   Foo(const Foo&);   // copy constructor
   // ...
};
//  When copy initialization happens and that copy initialization requires either
//  the copy constructor or the move constructor.
//  Copy initialization happens not only when we define variables using an =, but also when we
//  • Pass an object as an argument to a parameter of nonreference type
//  • Return an object from a function that has a nonreference return type
//  • Brace initialize the elements in an array or the members of an aggregate class (§ 7.5.5, p. 298)
//  Some class types also use copy initialization for the objects they allocate.
//  For example, the library containers copy initialize their elements when we
//  initialize the container, or when we call an insert or push member (§ 9.3.1, p. 342).
//  By contrast, elements created by an emplace member are direct initialized (§ 9.3.1, p. 345).
//!
//! Exercise 13.2: Explain why the following declaration is illegal:

//!       Sales_data::Sales_data(Sales_data rhs);
//  The copy constructor’s own parameter must be a reference. If that parameter were not a
//  reference, then the call would never succeed—to call the copy constructor, we’d need to
//  use the copy constructor to copy the argument, but to copy the argument, we’d need to
//  call the copy constructor, and so on indefinitely. Hence there is a logic dead lock here.
//!
//! Exercise 13.3:
//! What happens when we copy a StrBlob? What about StrBlobPtrs?
//  See below.
//!


#include "StrBlob.h"

int main()
{
    /**
     * @brief   ex13.3. Use debug step by step to understand the whole procedure
     */
    //! default constructor is called making the shared_ptr within it point to ,say, @0x8803018.
    //! usecount    ==  1
    //! weakcount   ==  1
    StrBlob sb;


    //! copy constructor is called making the pointer point to the same address i.e.@0x8803018.
    //! usecount    ==  2
    //! weakcount   ==  1
    StrBlob sb_duplic = sb;


    //! default constructor. the weak pointer inside points to the same address @0x8803018.
    //! usecount    ==  2
    //! weakcount   ==  2
    StrBlobPtr sb_p(sb);


    //! copy constructor is called, the pointer points to the same address i.e.@0x8803018
    //! usecount    ==  2
    //! weakcount   ==  3
    StrBlobPtr sb_p_duplic = sb_p;

    //! For the rationale that the weekcount start by 1 rather than 0 ,go to the post on SO:
    //! http://stackoverflow.com/questions/5671241/how-does-weak-ptr-work



    return 0;
}
