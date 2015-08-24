//
//  ex13_18.cpp
//  Exercise 13.18
//
//  Created by pezy on 1/15/15.
//
//  Define an Employee class that contains an employee name and a unique employee identifier.
//  Give the class a default constructor and a constructor that
//  takes a string representing the employee’s name.
//  Each constructor should generate a unique ID by incrementing a static data member.
//

#include "ex13_18.h"

int Employee::s_increment = 0;

Employee::Employee() {
    id_ = s_increment++;
}

Employee::Employee(const string &name) {
    id_ = s_increment++;
    name_ = name;
}

int main()
{
	
	return 0;
}
