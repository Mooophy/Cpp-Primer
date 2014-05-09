/***************************************************************************
 *  @file       string.h
 *  @author     Alan.W
 *  @date       06  JAN 2014
 *  @remark     move constructor and move assignment added
 *              --07.Jan.2014
 *              operator << added   --  10.Jan.2014
 ***************************************************************************/

#ifndef STRING_H
#define STRING_H

#include <memory>
#include <string>

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
    friend bool operator == (const String& lhs, const String& rhs);
    friend bool operator != (const String& lhs, const String& rhs);

    friend std::ostream&
    operator << (std::ostream& os, const String& s);
public:
    //! default constructor
    String();

    //! constructor taking C-style string i.e. a char array terminated with'\0'.
    explicit String(const char * const c);

    //! copy constructor
    explicit String(const String& s);

    //! move constructor    --07.Jan.2014
    String(String&& s) noexcept;

    //! operator =
    String& operator = (const String& rhs);

    //! move operator =     --07.Jan.2014
    String& operator = (String&& rhs) noexcept;

    //! destructor
    ~String();

    //! members
    char* begin() const  { return elements;   }
    char* end()   const  { return first_free; }

    char * begin()       { return elements;   }
    char * end()         { return first_free; }

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

std::ostream&
operator << (std::ostream& os, const String& s);

inline bool
operator == (const String& lhs, const String& rhs)
{
    if(lhs.size() == rhs.size())
    {
        auto r = rhs.begin();
        for(auto l = lhs.begin(); l != lhs.end(); ++l)
        {
            if (*l != *r)   return false;
            else            ++r;
        }

        return true;    //  the only place where true is returned
    }
    else
        return false;
}

inline bool
operator != (const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

#endif // STRING_H
