#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> iv = {0,1,2,3,1,4,1,1,5,6};
    vector<int>::size_type iter = 0, mid = iv.size() / 2;
    int some_value = 1;
    while (iter != mid) {
        if (iv[iter] == some_value) {
            iv.insert(iv.begin(), 2 * some_value);
            ++iter, ++mid; // update iter and mid for new vector
        }
        ++iter; // update iter for while loop
    }
    for (const auto &i : iv)
        std::cout << i << std::endl;
    return 0;
}
