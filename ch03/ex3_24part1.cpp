//!@Alan
//!
//!Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.
//!
//!Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair
//!of adjacent elements. Change your program so that it prints the sum of the first
//!and last elements, followed by the sum of the second and second-to-last, and so on.
//!
//!Part 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i;

    cout<<"Please Enter:\n";
    while (cin>>i)
    {
        v.push_back(i);
        if(v.end() - v.begin() <=1)
        {
            cout<<"too few elements in the vector\n";
        }
        else
        {
            cout<<"--The vector:\n";
            for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
            {
                cout<<*it<<" ";
            }

            for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
            {
                if(it+1 < v.end())
                {
                    cout<<"--The adjacent sum="<<*it +*(it+1)<<"\n";
                }
            }
        }
    }
    return 0;
}
