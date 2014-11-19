/***************************************************************************
 *  @file       main.cpp
 *  @author     Queequeg
 *  @date       19  Nov 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 17.14
//! Write several regular expressions designed to trigger various errors.
//! Run your program to see what output your compiler generates for each error.

//! Exercise 17.15
//! Write  a program using the pattern that finds word that violate the
//! "i before e except after c" rule. Have your program prompt the user to
//! supply a word and indicate whether the word is okay or not. Test your
//! program with words that do and do not violate the rule.

//! Exercise 17.16
//! What would happen if your regex object in the previous program were
//! initialized with "[^c]ei"? Test your program using that pattern to see
//! whether your expectations were correct.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include <regex>
using std::regex;
using std::regex_error;

int main()
{
    //! for ex17.14
    //! error_brack
    try{
        regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    }
    catch(regex_error e)
    {
        cout << e.what() << " code: " << e.code() << endl;
    }

    //! for ex17.15
    regex r("[[:alpha:]]*e[[:alpha:]]*i[[:alpha:]]*c[[:alpha:]]*", regex::icase);
    string s;
    cout << "Please input a word! Input 'q' to quit!" << endl;
    while(cin >> s && s != "q")
    {
        if(std::regex_match(s, r))
            cout << "Input word " << s << " is okay!" << endl;
    }
    return 0;
}
