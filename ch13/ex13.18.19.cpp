/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       31  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 13.18:
//! Define an Employee class that contains an employee name and a unique employee
//! identifier. Give the class a default constructor and a constructor that takes a
//! string representing the employee’s name. Each constructor should generate a unique
//! ID by incrementing a static data member.
//!
//! Exercise 13.19:
//! Does your Employee class need to define its own versions of the copy-control members?
//! If so, why? If not, why not? Implement whatever copy-control members you think Employee
//! needs.
//  Yes it need the user-defined copy constructor and copy-assignment operator, which makes
//  sure that each object has unique id.The user-defined destructor is not required.
//!

#include <string>
#include <iostream>
#include <vector>
#include <memory>

//! ex13.18
class Employee
{
public:
    //! constructors
    Employee() : name(std::string()), id(idGenerator()) { }
    Employee(const std::string& n) : name(n), id(idGenerator()) { }

    //! copy constructor and copy assignment operator for ex13.19
    Employee(const Employee& e) : name(e.name), id(idGenerator()) { }
    Employee&
    operator = (const Employee& e)
    {
        name = e.name;
        id   = idGenerator();
        return *this;
    }


    unsigned    idGenerator();
    std::string name;
    unsigned    id;
};

int main()
{
    Employee e1;
    Employee e2("sss");

    e1 =e2;

    std::cout << e1.id << " " << e2.id;
    std::cout << e1.name <<"\n";
    std::cout << e2.name <<"\n";

    return 0;
}

inline unsigned
Employee::idGenerator()
{
    static unsigned i = 0;
    return ++i;
}
