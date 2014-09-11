#include <iostream>
#include <iterator>

using std::begin; using std::end; using std::cout; using std::endl;

int main()
{
    int arr[10];
    int *b = begin(arr);
    int *e = end(arr);
    
    for (int *i = b; i != e; ++i)
      *i = 0;
      
    for (auto i : arr)
      cout << i << " ";
    cout << endl;

    return 0;
}
