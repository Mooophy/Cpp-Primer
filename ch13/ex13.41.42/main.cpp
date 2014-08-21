/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.41:
//! Why did we use postfix increment in the call to construct inside push_back?
//! What would happen if it used the prefix increment?
//  The prefix operator++ does a single operation -- increment the value.
//  The postfix operator++ does three operations -- save the current value,
//  increment the value, return the old value.
//
//  The prefix version is conceptually simpler, and is always (up to bizarre
//  operator overloads) at least as efficient as the postfix version.
//  --From SO
//
//          alloc.construct(first_free++, s);
//
//  Hence, if prefix increment is used instead, alloc.construct will jump over
//  one place leaving it unconstructed. Any operation ,like dereference or destruction,
//  on this address would be a disaster.
//
//!
//! Exercise 13.42:
//! Test your StrVec class by using it in place of the vector<string> in your
//! TextQuery and QueryResult classes (§ 12.3, p. 484).
//!

#include <iostream>
#include <string>
#include <vector>

#include "queryresult.h"
#include "textquery.h"


void runQueries(std::ifstream &infile);
int main()
{
    std::ifstream fin("test.txt");
    runQueries(fin);
    return 0;
}

void runQueries(std::ifstream &infile)
{

    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;

        if (!(std::cin >> s) || s == "q") break;

        print(std::cout, tq.query(s)) << std::endl;
    }
}
