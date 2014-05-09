//!@Alan
//!
//! Exercise 6.12:
//! Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use
//! references instead of pointers to swap the value of two ints. Which
//! version do you think would be easier to use and why?
//  The version using reference is easier.
//!



#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void swap(int& _n1, int& _n2);

int main()
{
    int n1, n2;

    cout<<"Please Enter:\n";
    while(cin>>n1>>n2)
    {
        swap(n1, n2);
        cout<<n1<<" "<<n2<<endl;
    }

    return 0;
}

void swap(int &_n1, int &_n2)
{
    int temp;
    temp = _n1;
    _n1 = _n2;
    _n2 = temp;

}
