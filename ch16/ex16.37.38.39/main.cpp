/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       07  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.37:
// The library max function has two function parameters and returns the
// larger of its arguments. This function has one template type parameter.
// Could you call max passing it an int and a double? If so, how? If not,
// why not?
//  Yes, just offer an explicit template argument, like:
//  int a = 1;
//  double b = 2;
//  std::max<double>(a, b);
//
// Exercise 16.38:
// When we call make_shared (§ 12.1.1, p. 451), we have to provide an
// explicit template argument. Explain why that argument is needed and
// how it is used.
//
//  without specified type given, make_shared has no possibility to
//  to determine how big the size it should allocate, which is the reason.
//
//  Depending on the type specified, make_shared allocates proper size of memory
//  space and returns a proper type of shared_ptr pointing to it.
//
// Exercise 16.39:
// Use an explicit template argument to make it sensible to pass two string
// literals to the original version of compare from § 16.1.1 (p. 652).
//


#include <iostream>


template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    std::cout << compare<std::string>("sss","aaa") << "\n";
}
