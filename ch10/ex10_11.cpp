// @Alan
// Exercise 10.11:
// Write a program that uses stable_sort and isShorter to sort a vector passed
// to your version of elimDups.
// Print the vector to verify that your program is correct.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

// print a container like vector, deque, list, etc.
template<typename Sequence>
inline std::ostream& println(Sequence const& seq)
{
    for(auto const& elem : seq) std::cout << elem << " ";
    std::cout << std::endl;

    return std::cout;
}


inline bool
is_shorter(std::string const& lhs, std::string const& rhs)
{
    return  lhs.size() < rhs.size();
}


void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}


int main()
{
    std::vector<std::string> v{
        "1234", "1234", "1234", "Hi", "alan", "wang"
    };
    elimdups(v);
    std::stable_sort(v.begin(), v.end(), is_shorter);
    std::cout << "ex10.11 :\n";
    println(v);

    return 0;
}
