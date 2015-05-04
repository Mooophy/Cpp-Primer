#include <iostream>
#include <vector>
#include <iterator>

using std::cout; using std::endl; using std::vector;

int main()
{
    // use array
    int ia[10];
    for (auto i=0; i<10; ++i)
        ia[i] = i;

    int ia2[10];
    for (auto i=0; i<10; ++i)
        ia2[i] = ia[i];

    // use vector
    vector<int> iv(std::begin(ia2), std::end(ia2));
    vector<int> iv2(iv);

    for (auto i : iv2)
        cout << i << " ";
    cout << endl;

    return 0;
}
