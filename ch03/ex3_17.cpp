//
//@Author  @PEZY @Yue Wang 
//@Date    Aug. 2014 Jun.2015
//@Brief
// Read a sequence of words from cin and store the values a vector.
// After you've read all the words, process the vector and change each word to uppercase.
// Print the transformed elements, eight words to a line.
//

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> vec;
    for (string word; cin >> word; vec.push_back(word));
    for (auto &str : vec) for (auto &c : str) c = toupper(c);

    for (string::size_type i = 0; i != vec.size(); ++i)
    {
        if (i != 0 && i % 8 == 0) cout << endl;
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
