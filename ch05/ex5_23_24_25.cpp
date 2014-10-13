//!@Alan
//!
//! Exercise 5.23:
//! Write a program that reads two integers from the standard
//! input and prints the result of dividing the first number
//! by the second.
//!
//! Exercise 5.24:
//! Revise your program to throw an exception if the second
//! number is zero. Test your program with a zero input to see
//! what happens on your system if you don’t catch an exception.
//!
//  Without exception catching, the programme was terminated when
//  a zero was entered.
//!
//! Exercise 5.25:
//! Revise your program from the previous exercise to use a try
//! block to catch the exception. The catch clause should print
//! a message to the user and ask them to supply a new number and
//! repeat the code inside the try.
//!



#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    int n1,n2;

    cout<<"Please Enter two numbers:\n";

    while(cin>>n1>>n2)
    {
        if(n2==0)
        {
            try
            {
                throw std::runtime_error("invalid input,the second can not be zero!\n");
            }
            catch(std::runtime_error err)
            {
                cout<<err.what()
                      << "\nTry Again?  Enter y or n" << endl;
                char c;
                cin >> c;
                if (!cin || c == 'n')
                    break;      // break out of the while loop
            }

        }
        else
        {
            cout<<n1/n2<<endl;
        }



    }


    return 0;
}
