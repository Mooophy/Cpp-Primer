#include <iostream>
#include <vector>

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
    size_t index=0;
    vector<int> iv(10);
    for(auto &i : iv)
            i=index++;      // use post-increment operator to assign the value before it is incremented

    vector<int> iv2(iv);

    for (auto i : iv2)
        cout << i << " ";
    cout << endl;

    return 0;
}
