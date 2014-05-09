//!@Alan
//!
//! Exercise 6.10:
//! Using pointers, write a function to swap the values of two ints.
//! Test the function by calling it and printing the swapped values.
//!



#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void swap(int* _n1, int* _n2);

int main()
{
    int n1, n2;

    cout<<"Please Enter:\n";
    while(cin>>n1>>n2)
    {
        swap(&n1, &n2);
        cout<<n1<<" "<<n2<<endl;
    }

    return 0;
}

void swap(int* _n1, int* _n2)
{
    int temp;
    temp = *_n1;
    *_n1 = *_n2;
    *_n2 = temp;
}
