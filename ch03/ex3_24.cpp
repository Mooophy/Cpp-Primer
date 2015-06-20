#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl; using std::cin;

int main()
{
    vector<int> v;
    for (int buffer; cin >> buffer; v.push_back(buffer));

    if (v.size() < 2)
    {
        cout << " please enter at least two integers";
        return -1;
    }

    for (auto it = v.cbegin(); it + 1 != v.cend(); ++it)
        cout << *it + *(it + 1) << " ";
    cout << endl;

    for (auto lft = v.cbegin(), rht = v.cend() - 1; lft <= rht; ++lft, --rht)
        cout << *lft + *rht << " ";
    cout << endl;

    return 0;
}
