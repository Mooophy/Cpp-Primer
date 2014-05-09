/***************************************************************************
 *  @file       strvec.h
 *  @author     Alan.W
 *  @date       05  JAN 2014
 *  @remark     move constructor and move assignment added
 *              --07 JAN 2014
 *              12  JAN 2014    :   ==  !=  are added.
 *              13  JAN 2014    :   <   >   <=    >= are added
 *              14  JAN 2014    :   assignment taking initstatializer_list added
 ***************************************************************************/


#ifndef STRVEC_H
#define STRVEC_H

#include <string>

/**
 * @brief   The StrVec class  a std::vector like class without template
 *          std:string is the only type it holds.
 */
class StrVec
{
public:
    //! Big 3/5.
    StrVec():
        element(nullptr), first_free(nullptr), cap(nullptr)
    {}

    StrVec(std::initializer_list<std::string> l);

    explicit StrVec(const StrVec& s);

    explicit StrVec(StrVec&& s) noexcept;            //! move constructor 07.Jan.2014

    StrVec&
    operator =(const StrVec& rhs);

    StrVec&
    operator = (StrVec&& rhs) noexcept;      //! move  assignment 07.Jan.2014

    StrVec&
    operator =(std::initializer_list<std::string> l);

    ~StrVec();

    //! public members
    void push_back(const std::string &s);

    std::size_t size() const        { return first_free - element; }
    std::size_t capacity() const    { return cap - element;        }

    std::string* begin() const      { return element;    }
    std::string* end() const        { return first_free; }

    //! preallocate enough memory for specified number of elements
    void reserve(std::size_t n);

    //! resize as required.
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string& s);

private:

    //! data members
    std::string* element;       //  pointer to the first element
    std::string* first_free;    //  pointer to the first free element
    std::string* cap;           //  pointer to one past the end

    std::allocator<std::string> alloc;

    //! utilities for Big 3/5
    void reallocate();
    void chk_n_alloc()      { if (size() == capacity()) reallocate(); }
    void free();

    //! utilities added
    //! used in reallocate() reserve() and resize().
    void wy_alloc_n_move(std::size_t n);

    std::pair<std::string*, std::string*>
    alloc_n_copy (std::string* b, std::string* e);
};



//! compares each string inside the object.
inline bool
operator ==(const StrVec& lhs, const StrVec& rhs)
{
    //! compare sizes
    if(lhs.size() == rhs.size())
    {
        //! compare each string held.
        auto r = rhs.begin();
        for (auto l = lhs.begin(); l != lhs.end(); ++l)
        {
            if(*l != *r)    return false;
            else            ++r;
        }
        return true;    //the only place returns true.
    }
    else
        return false;
}

inline bool
operator !=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

inline bool
operator < (const StrVec& lhs, const StrVec& rhs)
{

    auto l =lhs.begin(),    r = rhs.begin();

    //! iterating through lhs and increment r
    while(l != lhs.end())
    {
        //! if rhs is shorter than lhs OR *l is greater than *r
        if(r == rhs.end() || *l > *r)   return false;
        else
            if (*l < *r)   return true;
            else    ++r, ++l;     //! when *l == *r and r has not reached the end.
   //!@bug: ~~~~~~~~~~~~~^^^ fixed: ++l is omitted at first. Now, it works.
    }

    //! if r reached end return false, true otherwise.
    return (r == rhs.end()) ? false : true;
}

inline bool
operator > (const StrVec& lhs, const StrVec& rhs)
{
    if(lhs == rhs)  return false;
    else    return !(lhs < rhs);
}

inline bool
operator >=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs < rhs);
}

inline bool
operator <=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs > rhs);
}
#endif // STRVEC_H
