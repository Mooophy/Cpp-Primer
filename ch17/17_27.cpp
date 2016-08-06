//exercise 17.27
//Write a program that reformats a nine-digit zip code as ddddd-dddd.

#include <iostream>
#include <regex>
#include <string>

using namespace std;

string pattern = "(\\d{5})([.- ])?(\\d{4})";
string fmt = "$1-$3";

regex r(pattern);
string s;


int main()
{
    while(getline(cin,s))
    {
        smatch result;
        regex_search(s,result, r);

        if(!result.empty())
        {
            cout<<result.format(fmt)<<endl;
        }
        else
        {
            cout<<"Sorry, No match."<<endl;
        }

    }
    return 0;
}
