//! @Alan
//!
//! Exercise 7.9:
//! Add operations to read and print Person objects to the code you wrote
//! for the exercises in § 7.1.2 (p. 260).
//!

#include <iostream>
#include <string>

struct Person
{
    std::string name;
    std::string address;

    std::string getName(void) const {return this->name;}
    std::string getAddress(void) const {return this->address;}
};


//!
//! \brief  Exercise 7.9
//!
std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);

int main()
{
    Person p;

    read(std::cin,p);
    print(std::cout,p);

    return 0;
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os<<p.getName()<<" "<<p.address;
    return os;
}


std::istream &read(std::istream &is, Person &p)
{
    is>>p.name>>p.address;
    return is;
}
