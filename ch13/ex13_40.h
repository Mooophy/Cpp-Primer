//
//  ex13_40.h
//  Exercise 13.40
//
//  Created by pezy on 2/3/15.
//
//  Add a constructor that takes an initializer_list<string> to your StrVec class.
//

#ifndef CP5_EX_13_40_H_
#define CP5_EX_13_40_H_

#include <memory>
#include <string>
#include <initializer_list>

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);

private:
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const std::string*, const std::string*);

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    std::allocator<std::string> alloc;
};

#endif
