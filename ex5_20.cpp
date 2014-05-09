//!@Alan
//!
//! Exercise 5.20:
//! Write a program to read a sequence of strings from the standard
//! input until either the same word occurs twice in succession or
//! all the words have been read. Use a while loop to read the text
//! one word at a time. Use the break statement to terminate the loop
//! if a word occurs twice in succession. Print the word if it occurs
//! twice in succession, or else print a message saying that no word
//! was repeated.
//!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string current_str, previous_str;

    cout<<"Please Enter:\n";
    while(cin>>current_str)
    {
        if(current_str.compare(previous_str)==0)
        {
            break;
        }
        previous_str = current_str;
    }

    cout<<"The repeated word is "
          <<previous_str
            <<std::endl;

    return 0;
}
