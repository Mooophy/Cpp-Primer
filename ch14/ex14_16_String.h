#ifndef CP5_STRING_H__
#define CP5_STRING_H__

#include <memory>
#include <iostream>

#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class String
{
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);

public:
    String() : String("") { }
    String(const char *);
    String(const String&);
    String& operator=(const String&);
    String(String &&) NOEXCEPT;
    String& operator=(String&&)NOEXCEPT;
    ~String();

    void push_back(const char);

    char* begin() const { return elements; }
    char* end() const { return last_elem; }

    const char *c_str() const { return elements; }
    size_t size() const { return last_elem - elements; }
    size_t length() const { return size(); }
    size_t capacity() const { return cap - elements; }

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, char);

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void chk_n_alloc() { if (first_free == cap) reallocate(); }

private:
    char *elements;
    char *last_elem;
    char *first_free;
    char *cap;
    std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&, const String&);
std::istream& operator>>(std::istream&, String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

#endif
