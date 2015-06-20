#include <iostream>
#include <vector>
using std::begin; using std::end; using std::cout; using std::endl; using std::vector; using std::size_t;

size_t array_size(const int arr[])
{
    return sizeof(arr) / sizeof(arr[0]);
}

bool compare(const int lhs[], const int rhs[])
{
    auto lsize = array_size(lhs);
    auto rsize = array_size(rhs);
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
    int arr2[3] = { 0, 1, 2 };
    cout << "The two arrays are " << (compare(arr1, arr2) ? "equal\n" : "unequal\n");

    vector<int> vec1 = { 0, 1, 2 };
    vector<int> vec2 = { 0, 1, 3 };
    cout << "The two vectors are " << (compare(vec1, vec2) ? "equal\n" : "unequal\n");

    return 0;
}
