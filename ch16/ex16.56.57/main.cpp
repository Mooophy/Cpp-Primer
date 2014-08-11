/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       16  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.56:
//! Write and test a variadic version of errorMsg.
//!
//! Exercise 16.57:
//! Compare your variadic version of errorMsg to the error_msg function in
//! § 6.2.6 (p. 220). What are the advantages and disadvantages of each
//! approach?
//  The error_msg takes initializer_list as the argument. So only the elements
//  stored in it must be the same or at least convertible. In contrast, the variadic
//  version provides better flexibility.
//!


#include <iostream>
#include <memory>
#include <sstream>


//! always declare first:

template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);

//! print any type we don't otherwise.
template<typename T> std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

//! print pointers as their pointer value, followed by the object to which the pointer points
template<typename T> std::string debug_rep(T* p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if(p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}

//! non-template version
std::string debug_rep(const std::string &s)
{
    return '"' + s + '"';
}

//! convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(char *p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
    return debug_rep(std::string(p));
}

//! function to end the recursion and print the last element
//! this function must be declared before the variadic version of
//! print is defined
template<typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
    //!           ^
    //! note: no seperator after the last element in the pack
}


//! this version of print will be called for all but the last element in the pack
template<typename T, typename... Args>
std::ostream&
print(std::ostream &os, const T &t, const Args&... rest)
{
    //! print the first argument
    os << t << ",";

    //! recursive call; print the other arguments
    return print(os,rest...);
}

//! call debug_rep on each argument in the call to print
template<typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args... rest)
{
    //! print(os,debug_rep(rest)...);
    return print(os,debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cout, 1,2,3,4,9.0f,"sss","alan");


}
