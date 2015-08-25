// @Yue Wang
//
// Exercise 9.38:
// Write a program to explore how vectors grow in the library you use.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
        std::cout << v.capacity() << std::endl;

    return 0;
}
