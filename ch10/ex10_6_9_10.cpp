//!
//! @author @Yue Wang @shbling @pezy @zzzkl
//! @date   01.12.2014
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
//  The aim of this design is to seperate the algorithms and the operation
//  provided by memeber function.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

template<typename Sequence>
inline std::ostream& println(Sequence const& seq)
{
    for(auto const& elem : seq)
        std::cout << elem << " ";
    std::cout << std::endl;
    return std::cout;
}

//! Exercise 10.9
void elimdups(std::vector<std::string> &vs)
{
    println(vs);

    //! sort
    std::sort(vs.begin(), vs.end());
    println(vs);

    //! put all duplicates at the end of the vector
    auto new_end = std::unique(vs.begin(),vs.end());
    println(vs);

    //! erase duplicates
    vs.erase(new_end, vs.end());
    println(vs);
}

int main()
{
    //! ex 10.6
    std::vector<int> v{1,2,3,4,5,6,7,8,9};
    std::fill_n(v.begin(),v.size(),0);
    std::cout << "ex10.6:\n";
    println(v);

    //! ex 10.9
    std::vector<std::string> vs{"a","v","a","s","a","a","a"};
    std::cout << "ex 10.9:\n";
    elimdups(vs);
    return 0;
}
//! output:
//ex10.6:
//0 0 0 0 0 0 0 0 0
//ex 10.9:
//a v a s a a a
//a a a a a s v
//a s v a a a a
//a s v
