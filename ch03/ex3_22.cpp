//
//Revise the loop that printed the first paragraph in text 
//to instead change the elements in text that correspond 
//to the first paragraph to all uppercase. 
//After you’ve updated text, print its contents.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector; using std::string; using std::cout; using std::cin; using std::isalpha;

int main()
{
    vector<string> text;
    for (string line; getline(cin, line); text.push_back(line));
    
    for (auto& word : text)
    {
        for (auto& ch : word)
            if (isalpha(ch)) ch = toupper(ch);
        cout << word << " ";
    }

    return 0;
}
