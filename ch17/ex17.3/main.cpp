/**
 * @brief ex17.03
 * 
 * @file main.cpp
 * @author huipengly
 * @date 2018-08-24
 */

//
// Exercise 17.3:
// Rewrite the TextQuery programs from § 12.3 (p. 484) to use a tuple instead
// of the QueryResult class. Explain which design you think is better and why.
//
//  The orignal way is more formal.The second way is quick to implement , but hard to
//  refactor.So the second way is better for testing.
//

#include "text_query.h"
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout; using std::endl; using std::cin; using std::cerr;
#include <string>
using std::string;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char const *argv[])
{
    ifstream input;
    if (argc >= 2)
    {
        input.open(argv[1]);
    }
    else
    {
        cerr << "please input filename after program." << endl;
        return -1;
    }
    if (!input)
    {
        cerr << "open file failed!" << endl;
        return -2;
    }
    runQueries(input);
    return 0;
}