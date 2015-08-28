// @Alan @pezy
//
// Exercise 10.42:
// Reimplement the program that eliminated duplicate words that
// we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
//

#include <iostream>
#include <string>
#include <list>

using std::string; using std::list;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> l = { "aa", "aa", "aa", "aa", "aasss", "aa" };
    elimDups(l);
    for (const auto& e : l)
        std::cout << e << " ";
    std::cout << std::endl;
}
