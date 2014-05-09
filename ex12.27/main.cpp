/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       27  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.27:
//! The TextQuery and QueryResult classes use only capabilities that we have
//! already covered. Without looking ahead, write your own versions of these
//! classes.
//!



#include <wy_textquery.h>
#include <wy_queryresult.h>

int main()
{
    /**
     * @brief the codes below are copied from Page 486 using for testing.
     */
    std::ifstream fin("test.txt");

    wy_textQuery tq(fin);
    while (true)
    {
        std::cout << "====enter word to look for, or q to quit:\n";

        std::string s;
        if (!(std::cin >> s) || s == "q") break;

        print(std::cout, tq.query(s)) ;
    }

    return 0;
}
