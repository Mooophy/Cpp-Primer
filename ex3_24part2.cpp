//!@Alan
//!
//!Exercise 3.24:
//!Redo the last exercise from § 3.3.3 (p. 105) using iterators.
//!
//!Exercise 3.20:
//!Read a set of integers into a vector. Print the sum of each pair
//!of adjacent elements.
//!
//!Change your program so that it prints the sum of the first
//!and last elements, followed by the sum of the second and second-to-last, and so on.
//!
//!Part 2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i;

    cout<<"Please Enter:\n";
    while(cin>>i)
    {
        v.push_back(i);

        cout<<"vector=\n";
        for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
        {
            cout<<*it<<" ";
        }

        cout<<"\noutput=\n";

        //!note:    v.size()/2 is ok. v.begin()/2 is invalid.
        for(vector<int>::iterator it=v.begin(); it != v.begin() + v.size()/2 + 1; it++)
        {
            cout<< *it+*(v.end() - it -1 + v.begin())
                  <<" ";
        }

    }

    return 0;
}
