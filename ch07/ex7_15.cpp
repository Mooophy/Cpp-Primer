//! @Alan
//!
//! Exercise 7.15:
//! Add appropriate constructors to your Person class.
//!

#include <iostream>
#include <string>

struct Person
{
    //!
    //! @brief  Exercise 7.15
    //!
    Person() =default;
    Person(const std::string &nm, const std::string &add) {this->name = nm; this->address = add;}
    Person(std::istream &);

    std::string name;
    std::string address;

    std::string getName(void) const {return this->name;}
    std::string getAddress(void) const {return this->address;}
};

std::istream &read(std::istream &is, Person &p);
std::ostream &print(std::ostream &os, const Person &p);


//!
//! @brief  Exercise 7.15
//!
Person::Person(std::istream &is)
{
    read(is, *this);
}

int main()
{
    //Person p;
    //Person p("Alan","dd zz aa");
    Person p(std::cin);

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
