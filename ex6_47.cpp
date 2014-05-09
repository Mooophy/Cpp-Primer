//! @Alan
//!
//! Exercise 6.47:
//! Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that
//! used recursion to print the contents of a vector to conditionally print
//! information about its execution. For example, you might print the size
//! of the vector on each call. Compile and run the program with debugging
//! turned on and again with it turned off.
//!

#define NDEBUG //here to toggle NDEBUG

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;




//!
//! @brief      a better approach
//!
//! @author     @Shafik Yaghmour from Stack Overflow.
//!
template <typename Iterator>
void printVector( Iterator first, Iterator last);

int main()
{
    string s;
    vector<string> v;

    cout<<"Please Enter:\n";
    while(cin>>s)
    {
        v.push_back(s);

#ifndef NDEBUG
        cout << v.size() << std::endl;
#endif


        printVector(v.begin(),v.end());
    }
}

//!
//! @brief      a better approach
//!
//! @author     @Shafik Yaghmour from Stack Overflow.
//!
template <typename Iterator>
void printVector( Iterator first, Iterator last)
{
    if( first != last )
    {
        std::cout << *first << " " ;
        printVector( std::next( first ), last ) ;
    }
}
