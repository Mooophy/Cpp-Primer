/***************************************************************************
 *  @file       wy_StrBlob.h
 *  @author     Alan.W
 *  @date       25  DEC 2013
 *  @remark
 ***************************************************************************/

//!
//! Exercise 12.19:
//! Define your own version of StrBlobPtr and update your StrBlob class with
//! the appropriate friend declaration and begin and end members.
//  Discussion on Stack Overflow:
//  http://stackoverflow.com/questions/20768083/using-qt-creator-why-cant-my-class-header-compile
//!

#ifndef WY_STRBLOB_H
#define WY_STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

class wy_StrBlobPtr;
class wy_ConstStrBlobPtr;

/**
 * @brief shared_ptr to a dynamicly allocated vector.
 */
class wy_StrBlob
{
    friend class wy_StrBlobPtr;
    friend class wy_ConstStrBlobPtr;

public:
    typedef std::vector<std::string>::size_type size_type;

    //! Constructors
    wy_StrBlob() :
        data(std::make_shared<std::vector<std::string>>()) {}

    wy_StrBlob(std::initializer_list<std::string>   il) :
        data(std::make_shared<std::vector<std::string>>(il)) {}

    //! public members
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s);}
    void pop_back();

    std::string& front();
    const std::string& front() const ;

    std::string& back();
    const std::string& back() const ;

    /**
     * @attention   these two members must defined after wy_StrBlobPtr's
     *              declararion and before its definition.
     */
    wy_StrBlobPtr begin();
    wy_StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    //! throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

#endif // WY_STRBLOB_H
