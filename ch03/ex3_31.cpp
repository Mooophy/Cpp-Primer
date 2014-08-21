//!@Alan
//!
//!Exercise 3.31:
//!Write a program to define an array of ten ints. Give each element the
//!same value as its position in the array.
//!

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a[10];
    for(int i=0; i<=9; ++i)
    {
        cout<<"Please Enter the number " << i <<" of the array:\n";
        cin>>a[i];

    }

    cout<<"\narray=\n";
    for(int i=0; i<=9; ++i)
    {
        cout<<a[i]
             <<" ";
    }

    cout<<"\nthe new array=\n";
    for(int i=0; i<=9; ++i)
    {
        a[i]=i;
        cout<<a[i]
             <<" ";
    }


    return 0;
}
