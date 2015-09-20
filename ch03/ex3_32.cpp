#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

int main()
{
    // array
    int arr[10];
    for (int i = 0; i < 10; ++i) arr[i] = i;
    int arr2[10];
    for (int i = 0; i < 10; ++i) arr2[i] = arr[i];

    // vector
    vector<int> v(10);
    for (int i = 0; i != 10; ++i) v[i] = arr[i];
    vector<int> v2(v);
    for (auto i : v2) cout << i << " ";
    cout << endl;

    return 0;
}
