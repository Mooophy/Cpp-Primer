//! @Alan
//!
//! Exercise 7.27:
//! Add the move, set, and display operations to your version of Screen.
//! Test your class by executing the following code:
//  There are something wrong about the code for the wyScreen class. The
//  code below was changed referring to the code given by the book.
//!

#include <iostream>
#include <string>

class wyScreen
{
public:
    typedef std::string::size_type pos;

    //!  constructs:
    wyScreen() = default;
    wyScreen(const pos h, const pos w) : height(h), width(w), contents(h * w,' ') {  }
    wyScreen(const pos h, const pos w, char c) : height(h), width(w), contents(h * w, c){  }

    wyScreen &move(const pos r, const pos c);
    wyScreen &set(char c);
    wyScreen &set(pos r, pos col, char ch);

    wyScreen &display(std::ostream &os)
    {do_display(os);    return *this;}
    const wyScreen &display(std::ostream &os) const
    {do_display(os);    return *this;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(std::ostream &os) const {os << contents;}
};


int main()
{
    wyScreen sc(5, 5, 'X');
    sc.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    sc.display(std::cout);
    std::cout << "\n";

    return 0;
}

inline wyScreen&
wyScreen::move(const pos r, const pos c)
{
    cursor = r * width + c;
    return *this;
}

inline wyScreen&
wyScreen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline wyScreen&
wyScreen::set(wyScreen::pos r, wyScreen::pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}
