/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       28  Jan 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 15.31:
// Given that s1, s2, s3, and s4 are all strings, determine what objects are created in the following expressions:
//     (a) Query(s1) | Query(s2) & ~ Query(s3);
//          OrQuery, AndQuery, NotQuery, WordQuery
//     (b) Query(s1) | (Query(s2) & ~ Query(s3));
//          the same as the previous one
//     (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
//         OrQuery, AndQuery, WordQuery
// Exercise 15.32:
// What happens when an object of type Query is copied, moved, assigned, and destroyed?
//  copy:
//  While being copied, the synthesized copy constructor is called. It copies the data member
//  into the new object. Since in this case, the data member is a shared pointer, while
//  copying, the corresponding shared pointer points to the same address and
//  the use count from the both shared pointer becomes 2.
//
//  move:
//  while being moved, the synthesized move constructor is called. It moves the data member
//  into the new object. In this case, the shared pointer from the newly created
//  object will point to the address to which the original shared pointer pointed .
//  After the move operation, the use count of the shared pointer in the new object is 1,
//  whereas the pointer from the original object becomes nullptr.
//
//  copy assignment:
//  The synthesized copy assignment will be called. The outcome of this
//  operation is identical with the copy operation.
//
//  move assignment:
//  The synthesized move assignment will be called. The rest is the same as
//  the move operation.
//
//  destroy:
//  The synthesized destructor will be called. It will call the destructor of
//  shared_ptr which decrements the use count. If the count becomes zero, the destructor
//  from shared_ptr will delete the resources it point to.
//
// Exercise 15.33:
// What about objects of type Query_base?
//  Managed by the synthesized version. Since Query_base a abstract class, the object of
//  this type is essentially a subobject of its derived class.
//


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"


// this class is a simulation for class Query used to answer ex15.32
class Foo
{
public:
    Foo(const std::vector<std::string>& t) :
        text(new std::vector<std::string>(t)) { }

private:
    std::shared_ptr<std::vector<std::string>> text;

};
int main()
{
    std::vector<std::string> v = { "alan","alan","alan","alan","alan" };

    Foo foo(v);

    Foo bar = std::move(foo);

    return 0;
}
