// @Yue Wang Sep, 2015
//
// Exercise 11.8:
// Write a program that stores the excluded words in a vector
// instead of in a set. What are the advantages to using a set?
//  copied from the post on stack overflow:
//  1.No matter what elements you add or remove (unless you add
//  a duplicate, which is not allowed in a set), it will always
//  be ordered.
//  2.A vector has exactly and only the ordering you explicitly
//  give it. Items in a vector are where you put them. If you put
//  them in out of order, then they're out of order; you now need
//  to sort the container to put them back in order.
//  3.However, if you are constantly inserting and removing items
//  from the container, vector will run into many issues.
//  4.The time it takes to insert an item into a vector is proportional
//  to the number of items already in the vector. The time it takes
//  to insert an item into a set is proportional to the log of the
//  number of items. If the number of items is large, that's a huge
//  difference. Log(100, 000) is 17; that's a major speed improvement.
//  The same goes for removal.
//
//  http://stackoverflow.com/questions/8686725/what-is-the-difference-between-stdset-and-stdvector
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> exclude = { "aa", "bb", "cc", "dd", "ee", "ff" };
    for (std::string word; std::cout << "Enter plz:\n", std::cin >> word; )
    {
        auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_excluded ? "excluded" : "not excluded";
        std::cout << reply << std::endl;
    }

    return 0;
}
