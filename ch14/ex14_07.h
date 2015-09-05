#ifndef CP5_CH14_EX07_H_
#define CP5_CH14_EX07_H_

#include <memory>
#include <iostream>

class String
{
    friend std::ostream& operator<<(std::ostream&, const String&);
public:
    String() : String("") { }
    String(const char *);
    String(const String&);
    String& operator=(const String&);
    ~String();

    const char *c_str() const { return elements; }
    size_t size() const { return end - elements; }
    size_t length() const { return end - elements - 1; }

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};

std::ostream& operator<<(std::ostream&, const String&);

#endif //CP5_CH14_EX07_H_
