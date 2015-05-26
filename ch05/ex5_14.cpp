#include <iostream>
#include <string>

using std::cout; 
using std::cin; 
using std::endl; 
using std::string; 

int main()
{ 
    int count = 0,tmpcount = 0;
	string currentstr,str;
    for (string prestr; cin >> currentstr;) {
        if (currentstr == prestr) 
			++tmpcount;
        else {
			if (count < tmpcount){
				count = tmpcount;
				str = prestr;
			}
			prestr = currentstr; //only currentstr != prestr , the assign is needed
			tmpcount = 0;
		}
    }
	if (count < tmpcount){ // in case the last time that occurs tmpcount > count
		count = tmpcount; 
		str = currentstr;
	}
    if (count == 0) cout << "There's no duplicated string." << endl;
    else cout << "the word " << str << " occurred " << count + 1 << " times. " << endl;
    
    return 0;
}
