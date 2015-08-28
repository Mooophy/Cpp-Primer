/***************************************************************************
 *  @file       main.cpp
 *  @author     Queequeg
 *  @date       20  Nov 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
 //
// Exercise 18.12
// Organize the programs you have written to answer the questions in each
// chapter into their own namespaces. That is, namespace chapter15 would
// contain code for the Query programs and chapter10 would contain the
// TextQuery code. Using this structure, compile the Query code examples.

// Exercise 18.13
// When might you see use an unnamed namespace?
// http://stackoverflow.com/questions/154469/unnamed-anonymous-namespaces-vs-static-functions
// http://stackoverflow.com/questions/5312213/uses-of-unnamed-namespace-in-c

// Exercise 18.14
// Suppose we have the following declaration of the operator* that is a
// a member of the nested namespace mathLib::MatrixLib.
// How would you declare this operator in global scope?

// mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*
// (const mathLib::MatrixLib::matrix&, const mathLib::MatrixLib::matrix&);

// or :(provided by @lafener in #173)

//mathLib::MatrixLib::matrix mathLib::MatrixLib::operator* (const matrix&, const matrix&);

int main()
{
    return 0;
}
