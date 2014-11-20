//reads a string of characters including punctuation and writes what was read but with the punctuation removed.

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
  string s;
  cout << "Enter a string of characters including punctuation." << endl;
	while(getline(cin,s))
	{
		unsigned i = 0;
		while (i < s.length())
		{
			if(ispunct(s[i]))
			{
				s.erase(i,1);
				continue;
			}
			i++;
		}
		cout<<s<<endl;
	}
  return 0;
}
