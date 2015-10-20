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
        cout << (str1 <= str2 ? str1 : str2) 
             << " is less than the other. " << "\n\n"
             << "More? Enter yes or no: ";
        cin >> rsp;
    } while (rsp == "y" || rsp == "yes");
    return 0;
}
