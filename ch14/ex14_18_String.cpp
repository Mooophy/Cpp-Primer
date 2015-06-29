#include "ex14_18_String.h"
#include <algorithm>

//===========================================================================
//
//		operator - friend
//
//===========================================================================

std::ostream& operator<<(std::ostream &os, const String &lhs)
{
    os << lhs.c_str();
    return os;
}

std::istream& operator>>(std::istream &is, String &rhs)
{
    for (char c; (c = is.get()) != '\n';) {
        rhs.push_back(c);
    }
    return is;
}

bool operator==(const String &lhs, const String &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(rhs < lhs);
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

//===========================================================================
//
//		Constructors
//
//===========================================================================

String::String(const char *s)
{
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

//===========================================================================
//
//		Big 5
//
//===========================================================================

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.first_free);
}

String& String::operator = (const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = newstr.first;
    first_free = cap = newstr.second;
    last_elem = first_free - 1;
    return *this;
}

String::String(String &&s) NOEXCEPT : elements(s.elements), last_elem(s.last_elem), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.last_elem = s.first_free = s.cap = nullptr;
}

String& String::operator = (String &&rhs) NOEXCEPT
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        last_elem = rhs.last_elem;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.last_elem = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

String::~String()
{
    free();
}

//===========================================================================
//
//		members
//
//===========================================================================

void String::push_back(const char c)
{
    chk_n_alloc();
    *last_elem = c;
    last_elem = first_free;
    alloc.construct(first_free++, '\0');
}

void String::reallocate()
{
    //	\0    |    -
    //  ^          ^
    // elements    first_free
    // last_elem   cap

    auto newcapacity = size() ? 2 * (size() + 1) : 2;
    alloc_n_move(newcapacity);
}

void String::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size() + 1; ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    last_elem = dest - 1;
    first_free = dest;
    cap = elements + new_cap;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, first_free, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, cap - elements);
    }
}

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    first_free = cap = newstr.second;
    last_elem = first_free - 1;
}

void String::reserve(size_t new_cap)
{
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void String::resize(size_t count, char c)
{
    if (count > size()) {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; ++i) {
            *last_elem++ = c;
            alloc.construct(first_free++, '\0');
        }

    }
    else if (count < size()) {
        while (last_elem != elements + count) {
            --last_elem;
            alloc.destroy(--first_free);
        }
        *last_elem = '\0';
    }
}

void String::resize(size_t count)
{
    resize(count, ' ');
}
