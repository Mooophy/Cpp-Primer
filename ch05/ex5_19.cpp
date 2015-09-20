#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string rsp;
    do {
        cout << "Input two strings: ";
        string str1, str2;
        cin >> str1 >> str2;

        if(str1 < str2)
            cout<<str1<<" is less than "<<str2<< "\n\n"
             << "More? Enter yes or no: ";
        else if(str1>str2)
            cout<<str2<<" is less than "<<str1<< "\n\n"
             << "More? Enter yes or no: ";
        else
            cout<<"The two strings are the same."<<"\n\n"
            "More? Enter yes or no: ";

        cin >> rsp;

        for(int i=0;i<rsp.length();++i)
        {
            rsp[i]=tolower(rsp[i]);
        }

        if(rsp!="yes"&& rsp!="no")
        {
            cout<<"invalid response\n" <<"More? Enter yes or no: ";
            cin>>rsp;
            rsp[0]=tolower(rsp[0]);
        }
    } while (!rsp.empty() && rsp[0] == 'y');
    return 0;
}
