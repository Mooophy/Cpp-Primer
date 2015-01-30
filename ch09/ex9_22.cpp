#include <iostream>
#include <vector>

using namespace std;

void insertDoubleValue(vector<int> &iv, int some_val)
{
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid)
        if (*mid == some_val)
            mid = iv.insert(mid, 2 * some_val);
        else --mid;
}

void print(const vector<int> &iv)
{
    for (auto i : iv)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> iv = {0,1,2,3,4,5,6,7,8,9};
    iv.reserve(25);
    cout << iv.capacity() << endl;
    insertDoubleValue(iv, 4);
    print(iv);
}

