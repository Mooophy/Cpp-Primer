#include <iostream>
using std::cout; using std::endl;

int main()
{
    int arr[10];
    for (auto i = 0; i < 10; ++i) arr[i] = i;
    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
