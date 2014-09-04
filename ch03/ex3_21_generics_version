//!
//! @author Yue Wang
//! @date   4th Sep 2014
//!

#include <iostream>
#include <vector>

/**
 * @brief check
 * @param first
 * @param last
 *
 * generics version for ex3.21
 */
template<typename Iter>
void check(Iter first, Iter last)
{
    for(auto it = first; it != last; ++it)
        std::cout << *it << "\n";

    std::cout << "size = " << last - first << "\n\n";
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};

    check(v1.begin(),v1.end());
    check(v2.begin(),v2.end());
    check(v3.begin(),v3.end());
    check(v4.begin(),v4.end());
    check(v5.begin(),v5.end());
    check(v6.begin(),v6.end());
    check(v7.begin(),v7.end());

    return 0;
}
