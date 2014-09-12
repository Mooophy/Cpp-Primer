/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       29  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.30:
//! Define your own versions of the TextQuery and QueryResult classes and execute
//! the runQueries function from § 12.3.1 (p. 486).
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
