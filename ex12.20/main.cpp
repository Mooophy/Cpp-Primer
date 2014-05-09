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

#include <wy_strblob.h>
#include <wy_strblobptr.h>
#include <iostream>

#include <fstream>

int main()
{
    /**
     * @brief ex12.20
     */
    std::ifstream fin ("test.txt");
    wy_StrBlob sb;
    wy_StrBlobPtr wp(sb);
    std::string line;

    while(std::getline(fin, line))
    {
        sb.push_back(line);
        std::cout << wp.dereference() << "\n";
        wp.incr();
    }






    return 0;
}
