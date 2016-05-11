// @Alan
//
// Exercise 11.9:
// Define a map that associates words with a list of
// line numbers on which the word might occur.
//
// Exercise 11.10:
// Could we define a map from vector<int>::iterator
// to int? What about from list<int>::iterator to int?
// In each case, if not, why not?
//  vector<int>::iterator to int is ok , because < is defined
//  list<int>::iterator to int is not ok, as no < is defined.
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    // ex 11.9
    std::map<std::string, std::list<std::size_t>> m;

    // ex 11.10
    // can be declared.
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;


    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    // but when using this one the compiler complained that
    // error: no match for 'operator<' in '__x < __y'
    std::list<int> li;
    ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

    return 0;
}
