#include <iostream>
#include <vector>
using std::begin; using std::end; using std::cout; using std::endl; using std::vector; using std::size_t;

bool compare(const int lhs[], size_t lsize, const int rhs[], size_t rsize)
{
    if (lsize != rsize) return false;
    for (int i = 0; i != lsize; ++i)
        if (lhs[i] != rhs[i]) return false;
    return true;
}

bool compare(vector<int> const& lhs, vector<int>& rhs)
{
    return lhs == rhs;
}

int main()
{
    int arr1[3] = { 0, 1, 2 };
    int arr2[3] = { 0, 2, 4 };
    auto result = compare(arr1, sizeof(arr1) / sizeof(arr2[1]), arr2, sizeof(arr2[0]));
    cout << "The two arrays are " << (result ? "equal\n" : "unequal\n");

    vector<int> vec1 = { 0, 1, 2 };
    vector<int> vec2 = { 0, 1, 2 };
    result = compare(vec1, vec2);
    cout << "The two vectors are " << (result ? "equal\n" : "unequal\n");

    return 0;
}
