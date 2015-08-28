//
//  ex7_43.cpp
//  Exercise 7.43
//
//  Created by pezy on 11/20/14.
//

#include <vector> 

class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public:
    C() : def(0) { } // define the constructor of C.
private:
    NoDefault def;
};

int main()
{
    C c;
    
    std::vector<C> vec(10); 
    return 0;
}
