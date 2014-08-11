/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       03  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.29:
//! Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.
//  Because the parameters of the two swap functions have different types.
//!
//! Exercise 13.30:
//! Write and test a swap function for your valuelike version of HasPtr.
//! Give your swap a print statement that notes when it is executed.
//!
//! Exercise 13.31:
//! Give your class a < operator and define a vector of HasPtrs. Give that
//! vector some elements and then sort the vector. Note when swap is called.
//!
//! Exercise 13.32:
//! Would the pointerlike version of HasPtr benefit from defining a swap function?
//! If so, what is the benefit? If not, why not?
//  Essentially, the specific avoiding memory allocation is the reason why it improve
//  the performance. As for the pointerlike version, no dynamic memory allocation anyway.
//  Thus a specific version for it will not improve the performance.
//!

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//! revised for ex13.31
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator <(const HasPtr& lhs, const HasPtr& rhs);
public:
    //! default constructor.
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }

    //! copy constructor.
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) { }


    HasPtr&
    operator = (HasPtr rhs);
    //!        ^^ no const here

    //! destructor.
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int    i;
};

//! specific swap.
inline void
swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members

    std::cout <<"swapping!\n";
}

//! operator = using specific swap
HasPtr&
HasPtr::operator = (HasPtr rhs)
{
    swap(*this,rhs);
    return *this;
}

//! operator < overloading
inline bool
operator <(const HasPtr& lhs, const HasPtr& rhs)
{
    std::cout << "<ing\n";
    return *lhs.ps < *rhs.ps;
}

int main()
{
    HasPtr h1("dd"), h2("bb"), h3("cc");

    std::vector<HasPtr> v = {h1, h2, h3};

    std::sort(v.begin(), v.end());

    return 0;
}



