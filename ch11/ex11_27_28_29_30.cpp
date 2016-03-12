//
// @Yue Wang
//
// Exercise 11.27:
// What kinds of problems would you use count to solve?
// When might you use find instead?
//  I would use count to deal with multimap or multi multiset.
//  As for the associative container that have unique key, I would use find instead of count.
//
// Exercise 11.28:
// Define and initialize a variable to hold the result of
// calling find on a map from string to vector of int.
//
// Exercise 11.29:
// What do upper_bound, lower_bound, and equal_range return
// when you pass them a key that is not in the container?
//  If the element is not in the multimap, then lower_bound
//  and upper_bound will return equal iterators; both will
//  refer to the point at which the key can be inserted without
//  disrupting the order.
//
//  If no matching element is found, then both the first and
//  second iterators refer to the position where this key can
//  be inserted.
//
// Exercise 11.30:
// Explain the meaning of the operand pos.first->second used
// in the output expression of the final program in this section.
//     cout << pos.first->second << endl;
//              ^^^^^^^^^^^^^^^^^
//  pos                     a pair
//  pos.first               the iterator refering to the first element with the matching key
//  pos.first->second       the value part of the key-value of the first element with the matching key

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::map<std::string, std::vector<int>> m{ { "Alan",{ 1,2,3,4,5, } },{ "John",{ 1,5,6,7,8 } } };
    // ex11.28
    std::map<std::string, std::vector<int>>::iterator it = m.find("Alan");
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    return 0;
}
