//
// @author @Yue Wang @shbling @pezy @zzzkl
// @date   02.12.2014
//
// Exercise 10.20:
// The library defines an algorithm named count_if. Like find_if, this function takes
// a pair of iterators denoting an input range and a predicate that it applies to each
// element in the given range. count_if returns a count of how often the predicate is
// true. Use count_if to rewrite the portion of our program that counted how many words
// are greater than length 6.
//
// Exercise 10.21:
// Write a lambda that captures a local int variable and decrements that variable until
// it reaches 0. Once the variable is 0 additional calls should no longer decrement the
// variable. The lambda should return a bool that indicates whether the captured variable is 0.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::vector;
using std::count_if;
using std::string;


// Exercise 10.20
std::size_t bigerThan6(vector<string> const& v)
{
    return count_if(v.cbegin(), v.cend(), [](string const& s){
        return s.size() > 6;
    });
}


int main()
{
    // ex10.20
    vector<string> v{
        "alan","moophy","1234567","1234567","1234567","1234567"
    };
    std::cout << "ex10.20: " << bigerThan6(v) << std::endl;

    // ex10.21
    int i = 7;
    auto check_and_decrement = [&i](){ return --i ? false : true; };
    std::cout << "ex10.21: ";
    while(!check_and_decrement())
        std::cout << i << " ";
    std::cout << i << std::endl;

    return 0;
}
