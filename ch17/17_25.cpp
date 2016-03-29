//exercise 17.25
//Rewrite your phone program so that it writes only the first phone number for each person

#include <iostream>
#include <regex>
#include <string>

using namespace std;

string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
string fmt = "$2.$5.$7";
regex r(pattern);
string s;

int main()
{
    while(getline(cin,s))
    {
        smatch result;
        regex_search(s,result,r);
        if(!result.empty())
        {
        cout<<result.prefix()<<result.format(fmt)<<endl;
        }
        else
        {
            cout<<"Sorry, No match."<<endl;
        }
    }

    return 0;
}
