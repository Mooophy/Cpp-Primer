//!Exercise 3.20: Read a set of integers into a vector. ([Print the sum of each pair of
//!adjacent elements.].delete())  Change your program so that it prints the sum of the
//!first and last elements, followed by the sum of the second and second-to-last, and so
//!on.(part2)

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
            if(vi.size()%2==0)
            {
                cout<<"the size is:"<<vi.size()<<"\n";
                for(unsigned int i=0;i<vi.size()/2;i++)
                {
                    cout    <<"the output is "
                            << vi[vi.size()-i-1] + vi[i]
                            <<"\n";
                }
            }
        }

    }

    return 0;
}
