#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp) break; else tmp = read;

    if (cin.eof())  cout << "no word was repeated." << endl;
    else            cout << read << " occurs twice in succession." << endl;

    return 0;
}
