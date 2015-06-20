#include <iostream>
using std::cout; using std::endl;

int main()
{
    int arr[10];
    for (auto ptr = arr; ptr != arr + 10; ++ptr) *ptr = 0;

    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
