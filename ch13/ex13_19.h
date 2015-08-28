//
//  ex13_19.h
//  Exercise 13.19
//
//  Created by pezy on 1/15/15.
//
//  Does your Employee class need to define its own versions of the copy-control members?
//  If so, why? If not, why not?
//  Implement whatever copy-control members you think Employee needs.
//
//  Answer: No, cause there really is no sensible meaning. employee can't copy in real world.

#ifndef CP5_ex13_19_h
#define CP5_ex13_19_h

#include <string>
using std::string;

class Employee {
public:
    Employee();
    Employee(const string &name);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

#endif
