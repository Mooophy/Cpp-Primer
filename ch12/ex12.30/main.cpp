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
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile);  //  store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(std::cin >> s) || s == "q") break;
        // run the query and print the results
        print(std::cout, tq.query(s)) << std::endl;
    }
}
