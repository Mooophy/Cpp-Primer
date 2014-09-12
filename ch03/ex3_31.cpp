#include <cstddef>
#include <iostream>

using std::cout; using std::endl;

int main()
{
    int ia[10];
    for (size_t i=0; i<10; ++i)
        ia[i] = i;

    for (auto i : ia)
        cout << i << " ";
    cout << endl;

    return 0;
}
