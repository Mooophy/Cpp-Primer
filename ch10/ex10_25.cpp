//
//  ex10_25.cpp
//  Exercise 10.25
//
//  Created by pezy on 12/11/14.
//
//  @Brief  In the exercises for 10.3.2 (p.392) you wrote a version of biggies that uses partition.
//          Rewrite that function to use check_size and bind.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string; using std::vector;
using namespace std::placeholders;

void elimdups(vector<string> &vs)
{
    std::sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);
    auto iter = std::stable_partition(words.begin(), words.end(), bind(check_size, _1, sz));
    for_each(words.begin(), iter, [](const string &s){ std::cout << s << " "; });
}

int main()
{
    std::vector<std::string> v{
        "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };
    biggies(v, 4);
}
