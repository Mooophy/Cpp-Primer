#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string rsp;
    do {
        cout << "Input two strings: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << (str1.size() <= str2.size() ? str1 : str2) 
             << " is less than the other. " << "\n\n"
             << "More? Enter yes or no: ";
        cin >> rsp;
    } while (tolower(rsp[0]) == 'y');
    return 0;
}
