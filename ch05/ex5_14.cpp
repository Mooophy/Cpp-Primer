#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl; using std::string; using std::pair;

int main()
{ 
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr) ++count;
        else count = 0; 
        if (count > max_duplicated.second) max_duplicated = {prestr, count};
    }
    
    if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
    else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;
    
    return 0;
} 

//it's a easy way to understand for primary learner
/*
#include<iostream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
	vector<string> svec;
	string str;
	while (cin >> str)
	{
		svec.push_back(str);
	}
	vector<string>::iterator it = svec.begin();//auto it = svec.begin();
	int bigNum = 1, countNum = 1;
	string bigStr, countStr;
	while (it != svec.end()-1)
	{
		if (*it == *(it + 1))
		{
			++countNum;
			countStr = *it;
		}
		else
		{
			if (countNum>bigNum)
			{
				bigStr = countStr;
				bigNum = countNum;
			}
		}
		++it;
	}
	if (bigNum==1)
	{
		cout << " there is no  duplicated string." << endl;
	}
	else
	{
		cout << "the word " << bigStr << " occurred  " << bigNum << "times." << endl;
	}
	system("pause");
	return 0;
}
*/
