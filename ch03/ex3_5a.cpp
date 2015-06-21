//read strings from the standard input, concatenating what is read into one large string. 
//Print the concatenated string.
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string concatenated;
    for (string buffer; cin >> buffer; concatenated += buffer);
    cout << "The concatenated string is " << concatenated << endl;

    return 0;
}
