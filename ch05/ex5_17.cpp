#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

int main()
{
    vector<int> vec1{ 0, 1, 1, 2 };
    vector<int> vec2{ 0, 1, 1, 2, 3, 5, 8 };
    
    auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
    for (decltype(vec1.size()) i = 0; i != size; ++i) {
        if (vec1[i] != vec2[i]) { cout << "false" << endl; break; }
        if (i == size - 1) cout << "true" << endl;
    }
    
    return 0;
}
