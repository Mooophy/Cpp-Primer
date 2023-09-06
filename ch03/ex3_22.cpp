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
    string text;
    getline(cin, text);
    
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        if (isalpha(*it)) *it = toupper(*it); 
    }

    cout << text << '\n';
    return 0;
}
