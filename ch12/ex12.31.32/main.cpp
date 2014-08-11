/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//!
//! Exercise 12.31:
//! What difference(s) would it make if we used a vector instead of a set to hold
//! the line numbers? Which approach is better? Why?
//  The vector type can not ensure no duplicates. Hence, in terms of this programme set is a better
//  option.
//!
//! Exercise 12.32:
//! Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
//! vector<string> to hold the input file.
//!

#include "textquery.h"
#include "queryresult.h"

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
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(std::cin >> s) || s == "q") break;
        // run the query and print the results
        print(std::cout, tq.query(s)) << std::endl;
    }
}
