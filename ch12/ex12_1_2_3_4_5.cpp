/***************************************************************************
 *  @file       The code is for the exercises in C++ Primmer 5th Edition
 *  @author     Alan.W
 *  @date       22  DEC 2013
 *  @remark
 ***************************************************************************/
//!
//! Exercise 12.1:
//! How many elements do b1 and b2 have at the end of this code?
//  b1  :   4
//  b2  :   0
//!
//! Exercise 12.2:
//! Write your own version of the StrBlob class including the
//! const versions of front and back.
//!
//! Exercise 12.3:
//! Does this class need const versions of push_back and pop_back?
//! If so, add them. If not, why aren’t they needed?
//
//  You can certainly do this if you want to, but there doesn't seem to be any
//  logical reason. The compiler doesn't complain because this doesn't modify
//  data (which is a pointer) but rather the thing data points to, which is
//  perfectly legal to do with a const pointer. by David Schwartz.
//
//  Discussion over this exercise on Stack Overflow:
//  http://stackoverflow.com/questions/20725190/operating-on-dynamic-memory-is-it-meaningful-to-overload-a-const-memeber-functi
//!
//! Exercise 12.4:
//! In our check function we didn’t check whether i was greater than zero.
//! Why is it okay to omit that check?
//  Because the type of I is  std::vector<std::string>::size_type which
//  is an unsigned.When any arguement less than 0 is passed in, it will convert
//  to a number greater than 0. In short std::vector<std::string>::size_type
//  will ensure it is a positive number or 0.
//!
//! Exercise 12.5:
//! We did not make the constructor that takes an initializer_list explicit (§ 7.5.4, p. 296).
//! Discuss the pros and cons of this design choice.
//  keyword explicit prevents automaitc conversion from an initializer_list to StrBlob.
//  This design choice would easy to use but hard to debug.



#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

/**
 * @brief The wy_StrBlob class  for ex12.2
 */
class wy_StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;

    /**
     * @brief Constructors
     */
    wy_StrBlob() :
        data(std::make_shared<std::vector<std::string>>()) {}

    wy_StrBlob(std::initializer_list<std::string>   il) :
        data(std::make_shared<std::vector<std::string>>(il)) {}

    /**
     * @brief Member functions
     */
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    //! add and remove
    void push_back(const std::string &s) { data->push_back(s);}
    void pop_back();

    //! elements access
    std::string& front();
    const std::string& front() const ;

    std::string& back();
    const std::string& back() const ;

private:
    std::shared_ptr<std::vector<std::string>> data;
    //! throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

int main()
{
    return 0;
}

/**
 * @brief uility function that checks if the index is valid
 * @param i index
 * @param msg   message to be thown
 */
void wy_StrBlob::check(wy_StrBlob::size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw   std::out_of_range(msg);
    /** ^^^^^
     *  throw terminates the currtent function*/
}

/**
 * @brief return write/read reference to the first element
 */
std::string &
wy_StrBlob::front()
{
    check(0,"front on empty wy_StrBlob");
    return  data->front();
}

/**
 * @brief return a read-only (const) reference to the first element
 */
const std::string &
wy_StrBlob::front() const
{
    check(0, "front on empty wy_StrBlob");
    return  data->front();
}

/**
 * @brief return write/read reference to the last element
 */
std::string &
wy_StrBlob::back()
{
    check(0,"back on empty wy_StrBlob");
    return  data->back();
}
/**
 * @brief return a read-only (const) reference to the last element
 */
const std::string &
wy_StrBlob::back() const
{
    check(0, "back on empty wy_StrBlob");
    return data->back();
}

/**
 * @brief Remove last element
 */
void wy_StrBlob::pop_back()
{
    check(0, "pop_back on empty wy_StrBlob");
    data->pop_back();
}

