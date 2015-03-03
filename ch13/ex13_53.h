#ifndef CP5_ex13_53_h
#define CP5_ex13_53_h

#include <string>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string());
    HasPtr(const HasPtr &hp);
    HasPtr(HasPtr &&p) noexcept;
    HasPtr& operator=(HasPtr rhs);
    //HasPtr& operator=(const HasPtr &rhs);
    //HasPtr& operator=(HasPtr &&rhs) noexcept;
    ~HasPtr();

private:
    std::string *ps;
    int i;
};

#endif // CP5_ex13_53_h
