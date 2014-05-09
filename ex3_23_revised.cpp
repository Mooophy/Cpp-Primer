//!Exercise 3.23:
//!Write a program to create a vector with ten int elements.
//!Using an iterator, assign each element a value that is twice its current
//!value. Test your program by printing the vector.

#include <iostream>
#include <string>
#include <vector>

int main()
{
    /** @newcode
     *      17 Feb, 2014 @Alan
     *************************/

    //! a vector with ten int elements.
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    //! Using an iterator, assign each element a value that is twice its current
    for(auto it = v.begin(); it != v.end(); ++it)
        *it *=2;

    //! print the vector.
    for (const auto &i : v)
        std::cout << i << " ";


    /** @oldcode
      ***********/

    /*
    vector<int> v;
    int i;
    while(v.size()<=9)
    {
        cout<<"Please enter:\n";
        cin>>i;
        v.push_back(i);
        cout<<"the size is:"
              <<v.size()
                <<"\n";
    }

    cout << "The vector you input is:\n";
    for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
    {
        cout<<  *it<<"\n";
    }

    cout << "The vector after processed is:\n";
    for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
    {
        *it *=2;
        cout<<  *it<<"\n";
    }
    */
    return 0;
}

