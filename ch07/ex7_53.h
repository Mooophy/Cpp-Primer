//
//  ex7_53.h
//  Exercise 7.53
//
//  Created by pezy on 11/25/14.
//

#ifndef CP5_ex7_53_h
#define CP5_ex7_53_h

class Debug {
public:
    constexpr Debug(bool b = true) : rt(b), io(b), other(b) { }
    constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(0) { }
    constexpr bool any() { return rt || io || other; }
    
    void set_rt(bool b) { rt = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }
    
private:
    bool rt;        // runtime error
    bool io;        // I/O error
    bool other;     // the others
};

#endif
