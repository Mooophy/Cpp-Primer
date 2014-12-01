//!
//! @author @Yue Wang @shbling @pezy @zzzkl
//! @date   02.12.2014
//!
//! Exercise 10.18:
//! Rewrite biggies to use partition instead of find_if.
//!
//! Exercise 10.19:
//! Rewrite the previous exercise to use stable_partition, which like
//! stable_sort maintains the original element order in the paritioned
//! sequence.
//!


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::stable_sort;
using std::string;
using std::find_if;
using std::partition;


//! from ex 10.9
void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(),vs.end());
    vs.erase(new_end, vs.end());
}


//! ex10.18
void biggies_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);
    stable_sort(vs.begin(), vs.end(),[](string const& lhs, string const& rhs){
        return lhs.size() < rhs.size();
    });

    auto pivot = partition(vs.begin(), vs.end(),[sz](const std::string &s){
        return s.size() < sz;}
    );

    for(auto it = pivot; it != vs.cend(); ++it)
        std::cout << *it << " ";
}


//! ex10.19
void biggies_stable_partition(std::vector<std::string> &vs, std::size_t sz)
{
    elimdups(vs);
    stable_sort(vs.begin(), vs.end(),[](string const& lhs, string const& rhs){
        return lhs.size() < rhs.size();
    });

    auto pivot = stable_partition(vs.begin(), vs.end(),[sz](string const& s){
        return s.size() < sz;
    });

    for(auto it = pivot; it != vs.cend(); ++it)
        std::cout << *it << " ";
}


int main()
{
    //! ex10.18
    std::vector<std::string> v{
        "1","1234","1234","hi~", "alan", "alan"
    };
    std::cout << "ex10.18: ";
    biggies_partition(v,3);
    std::cout << std::endl;

    //! ex10.19
    std::vector<std::string> v2{
        "1","1234","1234","hi~", "alan", "alan"
    };
    std::cout << "ex10.19: ";
    biggies_stable_partition(v2,3);
    std::cout << std::endl;

    return 0;
}
//! output :
//!
//ex10.18: hi~ 1234 alan
//ex10.19: hi~ 1234 alan
