//!@Alan
//!
//!Exercise 3.31:
//!Write a program to define an array of ten ints. Give each element the
//!same value as its position in the array.
//!Exercise 3.32:
//!Copy the array you defined in the previous exercise into another array.
//!Rewrite your program to use vectors.
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

    int b[10];
    vector<int> v;
    for(int i=0; i<=9; ++i)
    {
        b[i]=a[i];
        v.push_back(b[i]);
    }

    return 0;
}
