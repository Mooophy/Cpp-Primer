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
#include <vector>

using namespace std;

int main()
{
    string current_str, previous_str, max_str, current_repeating_str;
    int current_repeating=0, max_repeating=0;

    cout<<"Please Enter:\n";
    while (cin>>current_str)
    {
        if(current_str.compare(previous_str) == 0)
        {
            current_repeating ++ ;
            current_repeating_str = current_str;
        }
        else
        {
            current_repeating = 0;
            current_repeating_str.clear();
        }

        if(current_repeating > max_repeating)
        {
            max_repeating = current_repeating;
            max_str = current_repeating_str;
        }

        cout<<"The Max repeating string now is "
              <<max_str
                <<"\nThe repeating times="
                  <<max_repeating
                    <<std::endl;

        previous_str = current_str;

    }

    return 0;
}
