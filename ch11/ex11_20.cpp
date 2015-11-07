// @Yue Wang @pezy
//
// Exercise 11.20:
// Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead
// of subscripting. Which program do you think is easier to write and read?
// Explain your reasoning.
//

#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;
using std::cin;
using std::cout;

int main()
{
    map<string, size_t> counts;
    for(string word; cin >> word;)
    {
        auto result = counts.insert({ word, 1 });
        if(!result.second)
            ++result.first->second;
    }
    for(auto const& count : counts)
        cout << count.first << " " << count.second << ((count.second > 1) ? " times\n" : " time\n");
}
