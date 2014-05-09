/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.19:
//! Define your own version of StrBlobPtr and update your StrBlob class with
//! the appropriate friend declaration and begin and end members.
//  Discussion on Stack Overflow:
//  http://stackoverflow.com/questions/20768083/using-qt-creator-why-cant-my-class-header-compile
//!
//! Exercise 12.20:
//! Write a program that reads an input file a line at a time into a StrBlob
//! and uses a StrBlobPtr to print each element in that StrBlob.
//!
//! Exercise 12.21:
//! We could have written StrBlobPtr’s deref member as follows:
//!      std::string& deref() const
//!      { return (*check(curr, "dereference past end"))[curr]; }
//! Which version do you think is better and why?
//  This version has worse readibility.Thus the original one is better
//!
//! Exercise 12.22:
//! What changes would need to be made to StrBlobPtr to create a class that can
//! be used with a const StrBlob? Define a class named ConstStrBlobPtr that can
//! point to a const StrBlob.
//!

#include <wy_strblob.h>
#include <wy_strblobptr.h>
#include <wy_conststrblobptr.h>
#include <iostream>

#include <fstream>

int main()
{
    /**
     * @brief test for ex12.22
     */
    const wy_StrBlob sb({"sss","aaa","ddd"});
    wy_ConstStrBlobPtr cwp(sb);

    for(int i = 0; i != 3; ++i)
    {
        std::cout << cwp.dereference() << "\n";
        cwp.incr();
    }


    return 0;
}
