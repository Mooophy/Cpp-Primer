// @Yue Wang
//
// Exercise 11.24:
// What does the following program do?
//     map<int, int> m;
//     m[0] = 1;
//  add a key-value pair { 0, 1 } into the map.
//
// Exercise 11.25:
// Contrast the following program with the one in the previous exercise
//     vector<int> v;
//     v[0] = 1;
//  UB, since it's trying to dereference an item out of range.
//
// Exercise 11.26:
// What type can be used to subscript a map? What type does the subscript
// operator return? Give a concrete example—that is, define a map and then
// write the types that can be used to subscript the map and the type that
// would be returned from the subscript operator.
//

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main()
{
    // ex11.26
    std::map<int, std::string> m = { { 1,"ss" },{ 2,"sz" } };
    using KeyType = std::map<int, std::string>::key_type;

    std::cout << "type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from the subscript operator: " << typeid(decltype(m[1])).name() << std::endl;

    return 0;
}
