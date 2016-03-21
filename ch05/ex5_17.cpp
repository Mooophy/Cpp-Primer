#include <iostream>
#include <vector>

using std::cout; using std::vector;

bool is_prefix(vector<int> const& lhs, vector<int> const& rhs)
{
    if(lhs.size() > rhs.size())
        return is_prefix(rhs, lhs);
    for(unsigned i = 0; i != lhs.size(); ++i)
        if(lhs[i] != rhs[i]) return false;
    return true;
}

int main()
{
    vector<int> l{ 0, 1, 1, 2 };
    vector<int> r{ 0, 1, 1, 2, 3, 5, 8 };
    cout << (is_prefix(r, l) ? "yes\n" : "no\n");

    return 0;
}

