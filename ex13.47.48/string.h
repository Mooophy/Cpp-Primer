/***************************************************************************
 *  @file       string.h
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark
 ***************************************************************************/

#ifndef STRING_H
#define STRING_H

#include <memory>

/**
 * @brief std::string like class without template
 *
 *        design:
 *
 *        [0][1][2][3][unconstructed chars][unallocated memory]
 *        ^           ^                    ^
 *        elements    first_free           cap
 */
class String
{
public:
    //! default constructor
    String();

    //! constructor taking C-style string i.e. a char array terminated with'\0'.
    explicit String(const char * const c);

    //! copy constructor
    explicit String(const String& s);

    //! operator =
    String& operator = (const String& rhs);

    //! destructor
    ~String();

    //! members
    char* begin() const  { return elements;   }
    char* end()   const  { return first_free; }

    std::size_t size()     const {return first_free - elements;  }
    std::size_t capacity() const {return cap - elements;         }



private:

    //! data members
    char* elements;
    char* first_free;
    char* cap;

    std::allocator<char> alloc;

    //! utillities for big 3
    void free();

};

#endif // STRING_H
