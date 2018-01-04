#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string str1,str2;
    do{
        if(!str1.empty() && !str2.empty()){
            cout<<"This string is less than the other: "<<((str1<str2)?str1:str2)<<endl;
            cout<<"Please, write the strings that you want to compare"<<endl;
        }
    }while(getline(cin,str1) && getline(cin,str2));

    return 0;
}
