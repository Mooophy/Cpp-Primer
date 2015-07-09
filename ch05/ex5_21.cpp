//  @Brief   Revise the program from the exercise in 5.5.1(p. 191)
//           so that it looks only for duplicated words that start with an uppercase letter. 
//  @See     Exercise 5.20
//  @frank67 Rewrite using the 'continue' statement. See #250

#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
    string curr, prev;
    bool no_twice = true;
    while (cin >> curr) 
    {
        if (isupper(curr[0]) && prev == curr)
        {
            cout << curr << ": occurs twice in succession." << endl;
            no_twice = false;
            break;
        }
        prev = curr;
    }

    if (no_twice)
        cout << "no word was repeated." << endl;

    return 0;
}
