// read two strings and report whether the strings are equal
// If not, report which of the two is larger.
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1 == str2)
            cout << "The two strings are equal." << endl;
        else
            cout << "The larger string is " << ((str1 > str2) ? str1 : str2);
    }

    return 0;
}
