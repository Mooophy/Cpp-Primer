//! @Alan
//!
//! Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.
//!


#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;


inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{


}
