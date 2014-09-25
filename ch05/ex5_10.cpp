#include <iostream>

using namespace std;

int main(void)
{
	char c;
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	while (cin >> c)
	{
		if (c == 'a' || c == 'A')
			++aCnt;
		else if (c == 'e' || c == 'E')
			++eCnt;
		else if (c == 'i' || c == 'I')
			++iCnt;
		else if (c == 'o' || c == 'O')
			++oCnt;
		else if (c == 'u' || c == 'U')
			++uCnt;
	}
	cout << "Num of vowel a :  " << aCnt << endl;
	cout << "Num of vowel e :  " << eCnt << endl;
	cout << "Num of vowel i :  " << iCnt << endl;
	cout << "Num of vowel o :  " << oCnt << endl;
	cout << "Num of vowel u :  " << uCnt << endl;
	return 0;
}