/*
    Name: Exercise 4.28
    Copyright: 
    Author: pezy
    Date: 28/09/14 13:08
    Description:  Write a program to print the size of each of the built-in types.
*/


#include <iostream>

using std::cout; using std::endl;

int main()
{
    cout << "bool\t\tis "      << sizeof(bool)        << "bytes." << endl;
    cout << "char\t\tis "      << sizeof(char)        << "bytes." << endl;
    cout << "wchar_t\t\tis "   << sizeof(wchar_t)     << "bytes." << endl;
    cout << "char16_t\tis "    << sizeof(char16_t)    << "bytes." << endl;
    cout << "char32_t\tis "    << sizeof(char32_t)    << "bytes." << endl;
    cout << "short\t\tis "     << sizeof(short)       << "bytes." << endl;
    cout << "int\t\tis "       << sizeof(int)         << "bytes." << endl;
    cout << "long\t\tis "      << sizeof(long)        << "bytes." << endl;
    cout << "long long\tis "   << sizeof(long long)   << "bytes." << endl;
    cout << "float\t\tis "     << sizeof(float)       << "bytes." << endl;
    cout << "double\t\tis "    << sizeof(double)      << "bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << "bytes." << endl;
    cout << endl;
    
    return 0;
}

//Print
/**************************/
//bool            is 1bytes.
//char            is 1bytes.
//wchar_t         is 2bytes.
//char16_t        is 2bytes.
//char32_t        is 4bytes.
//short           is 2bytes.
//int             is 4bytes.
//long            is 4bytes.
//long long       is 8bytes.
//float           is 4bytes.
//double          is 8bytes.
//long double     is 16bytes. 
