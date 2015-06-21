#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl; using std::begin; using std::end;

int main()
{
    vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr[10];
    for (int i = 0; i != v.size(); ++i) arr[i] = v[i];

    for (auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
