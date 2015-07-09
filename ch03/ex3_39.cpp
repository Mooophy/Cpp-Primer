#include <iostream>
#include <string>
#include <cstring>
using std::cout; using std::endl; using std::string;

int main()
{
    // use string.
    string s1("Mooophy"), s2("Pezy");
    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "Mooophy > Pezy" << endl;
    else
        cout << "Mooophy < Pezy" << endl;

    cout << "=========" << endl;

    // use C-Style character strings.
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";
    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "Wangyue < Pezy" << endl;
    else
        cout << "Wangyue > Pezy" << endl;

    return 0;
}
