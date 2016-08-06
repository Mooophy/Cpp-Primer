//exercise 17.24
//Write your own version of the program to reformat phone numbers.


#include <iostream>
#include <regex>
#include <string>

using namespace std;


string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
string format = "$2.$5.$7";
regex r(pattern);
string s;

int main()
{
    while(getline(cin,s))
    {
        cout<<regex_replace(s,r,format)<<endl;
    }

    return 0;
}
