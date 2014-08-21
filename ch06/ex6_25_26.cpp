//! @Alan
//!
//! Exercise 6.25: Write a main function that takes two arguments.
//! Concatenate the supplied arguments and print the resulting string.
//!
//! Exercise 6.26: Write a program that accepts the options presented
//! in this section. Print the values of the arguments passed to main.
//!



#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(int _argc, char **_argv)
{

    for(int i=0; i <= _argc; ++i)
    {
        cout<<_argv[i]
              <<" "
                <<endl;
    }


    return 0;
}
