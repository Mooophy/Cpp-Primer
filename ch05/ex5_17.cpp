#include <vector>

using std::vector;

int main()
{
        vector<int> vec1{0, 1, 1, 2}, vec2{0, 1, 1, 2, 3, 5, 8};
        auto size = vec1.size() < vec2.size() ? vec1.size() : vec2.size();
        for ( decltype(vec1.size()) i = 0; i != size; ++i ) {
                if ( vec1[i] != vec2[i] )
                        return -1;
                if ( i == size - 1 )
                        return 0;
        }
        return 0;
}
