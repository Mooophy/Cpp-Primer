#include <iostream>
#include <cstring>

using std::cout; using std::endl;

int main()
{
    const char* cs1 = "Wangyue";
    const char* cs2 = "Pezy";
    
    size_t size = strlen(cs1) + strlen(cs2) + 1;
    char* cs3 = new char(size);
    
    strcpy(cs3, cs1);
    strcat(cs3, " ");
    strcat(cs3, cs2);
    
    cout << cs3 << endl;
    
    delete cs3;

    return 0;
}
