#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &i : ivec)
        i = (i % 2) ? (i * 2) : i;

    //Check
    for (auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
