//
// @author @Yue Wang @shbling @pezy @zzzkl @Yue Wang
// @date   01.12.2014  Jun 2015
//
// Exercise 10.9:
// Implement your own version of elimDups. Test your program by printing
// the vector after you read the input, after the call to unique, and after
// the call to erase.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// print containers like vector, deque, list, etc.
template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream&
{
    for (auto const& elem : seq) 
        std::cout << elem << " ";
    return std::cout << std::endl;
}

auto eliminate_duplicates(std::vector<std::string> &vs) -> std::vector<std::string>&
{
    std::sort(vs.begin(), vs.end());
    println(vs);

    auto new_end = std::unique(vs.begin(), vs.end());
    println(vs);

    vs.erase(new_end, vs.end());
    return vs;
}

int main()
{
    std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };
    println(vs);
    println(eliminate_duplicates(vs));

    return 0;
}
