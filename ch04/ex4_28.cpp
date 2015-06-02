#include <iostream> // high level input/output operations.

int main()
{
    // by using method below only include what is needed.
    using std::cout;
    using std::endl;
    
    // void type
    cout << "void: nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << endl << endl;
    
    // boolean type
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;
    
    // charactor type
    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl << endl;
    
    // integers type
    cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
    cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;
    
    // floating point type
    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;
	
    // Fixed width integers
    cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
    cout << "uint8_t:\t" << sizeof(uint8_t) << " bytes" << endl;
    cout << "int16_t:\t" << sizeof(int16_t) << " bytes" << endl;
    cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
    cout << "int32_t:\t" << sizeof(int32_t) << " bytes" << endl;
    cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
    cout << "int64_t:\t" << sizeof(int64_t) << " bytes" << endl;
    cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;
    	
    return 0;
}

//Print
/**************************/
//void: nullptr_t 8 bytes

//bool:           1 bytes

//char:           1 bytes
//wchar_t:        2 bytes
//char16_t:       2 bytes
//char32_t:       4 bytes

//short:          2 bytes
//int:            4 bytes
//long:           4 bytes
//long long:      8 bytes

//float:          4 bytes
//double:         8 bytes
//long double:    16 bytes

//int8_t:         1 bytes
//uint8_t:        1 bytes
//int16_t:        2 bytes
//uint16_t:       2 bytes
//int32_t:        4 bytes
//uint32_t:       4 bytes
//int64_t:        8 bytes
//uint64_t:       8 bytes
