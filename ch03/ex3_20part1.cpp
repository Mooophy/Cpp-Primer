//Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of adjacent elements.
//part1


#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
    vector<int> vi;
    int i;
    int &i_r=i;

    while(cin>>i_r)
    {
        vi.push_back(i_r);
        if(vi.size()>1)
        {
            cout    <<"vi[" <<  vi.size()-1 <<  "] + vi["   <<vi.size()-2   <<"]= "
                    <<vi[vi.size()-1]+vi[vi.size()-2]
                    <<"\n";
        }

    }

    return 0;
}
