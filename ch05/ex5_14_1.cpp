// by Ocxs(https://github.com/Ocxs). 

#include <iostream>
using std::cin; using std::cout; using std::endl; 
#include <vector>
using std::vector;
#include <string>
using std::string;
 
int main()
{
	vector<string> svec;
	string str;
	while (cin>>str )
	{
		svec.push_back(str);
	}

	vector<string>::iterator it = svec.begin();//auto it = svec.begin();
	int bigNum = 1, countNum = 1;
	string bigStr, countStr;
	while (svec.size()>0 && it != svec.end() - 1)
	{
		if (*it == *(it + 1))
		{
			++countNum;
			countStr = *it;
		}
		else
		{
			countNum = 0;
		}
		if (countNum>bigNum)
		{
			bigStr = countStr;
			bigNum = countNum;
		}	
		++it;
	}
	
	if (bigNum == 1)
	{
		cout << "there is no duplicated string." << endl;
	}
	else
	{
		cout << "the word " << bigStr << " occurred  " << bigNum << " times." << endl;
	}
	return 0;
}
