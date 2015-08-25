/***************************************************************************
*  @file       main.cpp
*  @author     Yue Wang
*  @date       3  Mar 2014
                  Jun 2015   
*  @remark     This code is for the exercises from C++ Primer 5th Edition
*  @note
***************************************************************************/
//
// Exercise 17.1:
// Define a tuple that holds three int values and initialize the members to 10, 20, and 30.
//
// Exercise 17.2:
// Define a tuple that holds a string, a vector<string>, and a pair<string, int>.
//

#include <tuple>
#include <string>
#include <vector>

int main()
{
    auto three_ints = std::make_tuple(10, 20, 30);
    
    using SomeTuple = std::tuple < std::string, std::vector<std::string>, std::pair<std::string, int> > ;
    SomeTuple some_tuple;

    return 0;
}
