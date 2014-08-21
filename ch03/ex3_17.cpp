#include <iostream>
#include <string>
#include <vector>

using namespace std;
//using std::string;

//using namespace std;


int main()
{

    string str;

    vector<string> vec_str;
    while(cin>>str)
    {
        if(str.compare("e")==0)
        {
            break;
        }


        if(str.compare("q")!=0)
        {
            vec_str.push_back(str);
        }
        else
        {
            for (unsigned int i=0; i<vec_str.size();i++)
            {
                cout<<vec_str[i]
                      <<" ";


                if(i%7==0 && i>0)
                {
                    cout<<"\n";
                }
            }
            cout<<"\nthe size is "
                    <<vec_str.size()
                        <<"\n";
            vec_str.clear();
        }
    }

    return 0;
}
