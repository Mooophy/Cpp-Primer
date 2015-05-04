#include <cstddef>
#include <iostream>

using std::cout; using std::endl;

int main()
{
    int ia[10];
    int posi=0;
    for (size_t i=0; i<10; ++i,++posi)
        ia[i] = posi;

    for (auto i : ia)
        cout << i << " ";
    cout << endl;

    return 0;
}
