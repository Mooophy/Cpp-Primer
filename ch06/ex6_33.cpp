#include <iostream>
#include <vector>
using std::vector; using std::cout;
using Iter = vector<int>::const_iterator;

void print(Iter first, Iter last)
{
    if (first != last)
    {
        cout << *first << " ";
        print(++first, last);
    }
}

int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(vec.cbegin(), vec.cend());

    return 0;
}
