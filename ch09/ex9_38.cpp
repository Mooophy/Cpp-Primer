// @Yue Wang
//
// Exercise 9.38:
// Write a program to explore how vectors grow in the library you use.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ivec;
    auto prev = ivec.capacity();
    for (int i = 0; i < 128; ++i)
    {
        ivec.push_back(i);
        if(prev != ivec.capacity())
            cout << prev << "-> " << (prev = ivec.capacity()) << endl;
    }
    return 0;
}
