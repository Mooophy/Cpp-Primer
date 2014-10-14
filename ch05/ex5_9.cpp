#include <iostream>

using std::cout; using std::endl; using std::cin;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch)
    {
        if (ch == 'a') ++aCnt;
        else if (ch == 'e') ++eCnt;
        else if (ch == 'i') ++iCnt;
        else if (ch == 'o') ++oCnt;
        else if (ch == 'u') ++uCnt;
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
        << "Number of vowel e: \t" << eCnt << '\n'
        << "Number of vowel i: \t" << iCnt << '\n'
        << "Number of vowel o: \t" << oCnt << '\n'
        << "Number of vowel u: \t" << uCnt << endl;
    
    return 0;
}
