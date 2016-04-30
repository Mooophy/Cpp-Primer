// Print each number in the range specified by two integers.

#include <iostream>

using std::cout;
using std::cin;

void print_range(int lo, int hi)
{
    if (lo > hi)
    {
        print_range(hi, lo);
        return;
    }
    for (int i = lo; i != hi; ++i)
        cout << i << " ";
}

int main()
{
    int low = 0, high = 0;
    cout << "please input two integers:\n";
    cin >> low >> high;
    print_range(low, high);
    return 0;
}
