#include <iostream>
#include <string>
using std::string;
class Sales_data{
public:
    Sales_data() = default;
    ~Sales_data() = default;
    Sales_data(int i):a(i){}
    Sales_data(const Sales_data &rhs):a(rhs.a){}
    Sales_data& operator=(const Sales_data&rhs){
        a = rhs.a;
        return *this;
    }
private:
    int a = 0;
};

class Token{
public:
    Token():tok(INT),ival(0){}
    Token(const Token&t): tok(t.tok){copyUnion(t);}
    ~Token(){
        if(tok == STR) sval.~string();
        if(tok == SAL) item.~Sales_data();
    }
    Token& operator=(Token &&);
    Token(Token&&);
    Token& operator=(const Token&);
    Token& operator=(const string&);
    Token& operator=(const int&);
    Token& operator=(const char&);
    Token& operator=(const Sales_data&);
private:
    enum { INT, CHAR, STR, SAL} tok;
    union{
        char cval;
        int ival;
        std::string sval;
        Sales_data item;
    };
    void copyUnion(const Token&);
    //move edition
    void copyUnion(Token&&);
};
void Token::copyUnion(Token&& t){
    switch (t.tok) {
        case INT  : ival = t.ival; break;
        case CHAR : cval = t.cval; break;
        case STR  : std::move(t.sval);break;
        case SAL  : std::move(t.item); break;
    }
}
void Token::copyUnion(const Token &t){
    switch (t.tok) {
        case INT  : ival = t.ival; break;
        case CHAR : cval = t.cval; break;
        case STR  : new(&sval) string(t.sval);break;
        case SAL  : new(&item) Sales_data(t.item); break;
    }
}

Token& Token::operator=(const Token&t){
    if(tok == STR && t.tok != STR) sval.~string();
    if(tok == SAL && t.tok != SAL) item.~Sales_data();
    if(tok == STR && t.tok == STR) sval = t.sval;
    if(tok == SAL && t.tok == SAL) item = t.item;
    else copyUnion(t);
    tok = t.tok;
    return *this;
}

//move constructor
Token& Token::operator=(Token&& t){
    if(this != &t){
        this->~Token();
        copyUnion(t);
        tok = std::move(t.tok);
    }
    return *this;
}
Token::Token(Token &&t){
    copyUnion(t);
    tok = std::move(t.tok);
}



Token& Token::operator=(const Sales_data& rhs){
    if(tok == STR) sval.~string();
    if(tok == SAL)
        item = rhs;
    else
        new(&item) Sales_data(rhs);
    tok = SAL;
    return *this;
}
Token& Token::operator=(const int& i){
    if(tok == STR) sval.~string();
    if(tok == SAL) item.~Sales_data();
    ival = i;
    tok = INT;
    return *this;
}


int main(int argc, char const *argv[]) {
    Token s;
    Sales_data sal(5);
    s =  sal;
    int i = 5;
    std::cout << i << std::endl;
    return 0;
}
