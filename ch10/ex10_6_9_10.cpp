//! @Alan
//!
//! Exercise 10.6:
//! Using fill_n, write a program to set a sequence of int values to 0.
//!
//! Exercise 10.9:
//! Implement your own version of elimDups. Test your program by printing
//! the vector after you read the input, after the call to unique, and after
//! the call to erase.
//!
//! Exercise 10.10:
//! Why do you think the algorithms don’t change the size of containers?
//  The aim of this desigen is to seperate the algorithms and the operation
//  provided by memeber function.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>


//! Exercise 10.6:
void
set0(std::vector<int> &v);

//! Exercise 10.9
void
wy_elimdups(std::vector<std::string> &vs);

int main()
{
    //! Exercise 10.6
    std::vector<int> v;
    v.resize(10);
    set0(v);
    std::vector<int>::iterator iter=v.begin();
    std::cout<<*iter<<std::endl;
    //! Exercise 10.9
    std::vector<std::string> vs = {"a","v","a","s","a","a","a"};
    wy_elimdups(vs);
    return 0;
}

//! Exercise 10.6
void set0(std::vector<int> &v)
{
    std::fill_n( v.begin(), v.size(), 0 );
}

//! Exercise 10.9
void wy_elimdups(std::vector<std::string> &vs)
{
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! sort alphabetically
    std::sort(vs.begin(), vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    //! put all duplicates at the end of the vector
    //! and get the iterator pointing to the one past
    //! the last unique element.
    auto unique_iterator = std::unique(vs.begin(),vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";


    vs.erase(unique_iterator, vs.end());
    for (auto element : vs)
        std::cout << element
                  <<" ";
    std::cout <<"\n";
}
