#include "ex13_53.h"

int main()
{
    HasPtr hp1("hello"), hp2("World"), *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(*pH);
}

// when used copy-and-swap

//call constructor
//call constructor
//call constructor
//call copy constructor !!!
//call swap             !!!
//call destructor       !!!
//call move constructor !!!
//call swap             !!!
//call destructor       !!!
//call destructor
//call destructor

// when used two assignment operator.

//call constructor
//call constructor
//call constructor
//call copy assignment  !!!
//call move assignment  !!!
//call destructor
//call destructor
