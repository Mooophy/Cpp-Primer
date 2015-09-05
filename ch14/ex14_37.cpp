#include <iostream>
#include <vector>
#include <algorithm>

class IsEqual {
    int value;
public:
    IsEqual(int v) : value(v) { }
    bool operator()(int elem) {
        return elem == value;
    }
};

int main()
{
    std::vector<int> vec = { 3, 2, 1, 4, 3, 7, 8, 6 };
    std::replace_if(vec.begin(), vec.end(), IsEqual(3), 5);
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}
