//!@Alan
//!
//!Exercise 3.35: Using pointers, write a program to set the elements
//!in an array to zero.
//!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int scores[11];
    cout<<"the orignal array=\n";
    for(int* p = scores; p != &scores[11]; ++p)
    {
        cout<<*p
                <<" ";
    }

    cout<<"\nthe onew array=\n";
    for(int* p = scores; p != &scores[11]; ++p)
    {
        *p=0;
        cout<<*p
                <<" ";
    }

    return 0;
}
