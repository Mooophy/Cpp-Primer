//!
//! @author @Yue Wang @shbling @pezy @zzzkl
//! @date   01.12.2014
//!
//! Exercise 10.9:
//! Implement your own version of elimDups. Test your program by printing
//! the vector after you read the input, after the call to unique, and after
//! the call to erase.
//!

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//! print a container like vector,deque, list,etc.
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
//! ^^^^^^^^^^^^
//! @attention  Accessing from new_end to end() should be considered as a UB.
//!             As a result, it would behave differently on different platform.
//!             For detail, see : https://github.com/Mooophy/Cpp-Primer/pull/85#issuecomment-65016500

    //! erase duplicates
    vs.erase(new_end, vs.end());
    println(vs);
}

int main()
{
    //! ex 10.9
    std::vector<std::string> vs{"a","v","a","s","a","a","a"};
    std::cout << "ex 10.9:\n";
    elimdups(vs);
    return 0;
}
//! output:
//ex 10.9:
//a v a s a a a
//a a a a a s v
//a s v a a a a  // VS2013 or clang will have some differences. (a s v a a)
//a s v
