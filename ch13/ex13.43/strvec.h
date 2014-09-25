/***************************************************************************
 *  @file       strvec.h
 *  @author     Alan.W
 *  @date       05  JAN 2014
 *  @remark
 ***************************************************************************/


#ifndef STRVEC_H
#define STRVEC_H

#include <string>


class StrVec
{
public:
    //! Big 3/5.
    StrVec():
        element(nullptr), first_free(nullptr), cap(nullptr)
    {}

    StrVec(std::initializer_list<std::string> l);


    StrVec(const StrVec& s);

    StrVec&
    operator =(const StrVec& rhs);

    ~StrVec();

    //! public members
    void push_back(const std::string &s);

    std::size_t size() const        { return first_free - element; }
    std::size_t capacity() const    { return cap - element; }

    std::string* begin() const      { return element; }
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

    static std::allocator<std::string> alloc;

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

#endif // STRVEC_H
