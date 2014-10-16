#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string; using std::pair;

int main()
{ 
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr) { ++count; continue; }
        else if (count > max_duplicated.second) max_duplicated = {prestr, count};
        count = 0;
    }
    
    if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
    else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second+1 << " times. " << endl;
    
    return 0;
} 
