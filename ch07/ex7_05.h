//
//  ex7_05.h
//  Exercise 7.5
//
//  Created by pezy on 14/11/8.
//  Copyright (c) 2014 pezy. All rights reserved.
//

#ifndef CP5_ex7_05_h
#define CP5_ex7_05_h

#include <string>

class Person {
    std::string name;
    std::string address;
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

#endif

// Should these functions be const?

// Yes, A const following the parameter list indicates that this is a pointer to const.
// These functions my read but not write to the data members of the objects on which it is called.
