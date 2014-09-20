//!@Alan
//!
//! Exercise 5.14:
//! Write a program to read strings from standard input looking for duplicated
//! words. The program should find places in the input where one word is followed immediately
//! by itself. Keep track of the largest number of times a single repetition occurs and which
//! word is repeated. Print the maximum number of duplicates, or else print a message saying
//! that no word was repeated. For example, if the input is
//  how now now now brown cow cow
//! the output should indicate that the word now occurred three times.
//!

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string curr_str, pre_str, re_str;
    int cnt = 1, max = 1;
    cin >> pre_str;
    while (cin >> curr_str)
    {
        if (curr_str == pre_str)
        {
            ++cnt;
            if (cnt > max)
            {
                max = cnt;
                re_str = curr_str;
            }       
        }
        else
        {
            cnt = 1;
        }
        
        pre_str = curr_str;
    }
    if (!re_str.empty())
    {
        cout << re_str << " occurs " << max << " times" << endl;
    }
    else
    {
        cout << "no such number" << endl;
    }
    return 0;
}