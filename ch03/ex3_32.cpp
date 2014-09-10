#include <cstddef>
#include <iostream>
#include <vector>
#include <iterator>

using std::cout; using std::endl; using std::vector; using std::iterator;

int main()
{
    // use array
    int ia[10];
    for (size_t i=0; i<10; ++i)
        ia[i] = i;

    int ia2[10];
    for (size_t i=0; i<10; ++i)
        ia2[i] = ia[i];

    // use vector
    vector<int> iv(10);
    for (auto iter = iv.begin(); iter != iv.end(); ++iter)    
        *iter = iter - iv.begin();

    vector<int> iv2(iv);

    for (auto i : iv2)
        cout << i << " ";
    cout << endl;

    return 0;
}
