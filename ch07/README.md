Chapter 7. Classes
==================

## Exercise 7.1
> Write a version of the transaction-processing program from § 1.6 (p. 24) using the `Sales_data` class you defined for [Exercise 2.40](../ch02/README.md#exercise-240).
```c++
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;

struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = .0;
    double price = .0;
};

int main(int argc, char *argv[]) {
    Sales_data total;
    if (cin >> total.bookNo 
            >> total.bookName 
            >> total.units_sold 
            >> total.revenue 
            >> total.price) {
        Sales_data trans;
        while (cin >> trans.bookNo 
                   >> trans.bookName 
                   >> trans.units_sold 
                   >> trans.revenue 
                   >> trans.price) {
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue    += trans.revenue;
                total.price      += trans.price;
            } else {
                cout << total.bookNo << " " 
                     << total.bookName << " " 
                     << total.units_sold << " " 
                     << total.revenue << " " 
                     << total.price << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " 
             << total.bookName << " " 
             << total.units_sold << " " 
             << total.revenue << " " 
             << total.price << endl;
    } else {
        cerr << "Input Error!" << endl;
        return -1;
    }
    return 0;
}

```

## Exercise 7.2
> Add the `combine` and `isbn` members to the `Sales_data` class you wrote for [Exercise 2.41](../ch02/README.md#exercise-241) in § 2.6.2 (p. 76).
```c++
// filename: ex72.hpp
#ifndef __EX_7_2__
#define __EX_7_2__
struct Sales_data {
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = .0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
#endif // __EX_7_2__
```

## Exercise 7.3
> Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.
```c++
#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;

#include "ex72.hpp" // see Exercise 7.2

int main(int argc, char *argv[]) {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
```

## Exercise 7.4
> Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subsequent exercises will incrementally add features to this class.
```c++
struct Person {
    std::string name;
    std::string address;
};
```

## Exercise 7.5
> Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.
```c++
struct Person {
    std::string name;
    std::string address;

    auto getName() const -> const std::string& { return name; }
    auto getAddress() const -> const std::string& { return address; }
};
```

## Exercise 7.6
> Define your own version of the `add`, `read`, and `print` functions.
```c++
#ifndef __EX_7_6__
#define __EX_7_6__
#include <iostream>

struct Sales_data {
    std::string const& isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = .0;
};

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmember functions.
std::istream& read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
#endif // __EX_7_6__
```

## Exercise 7.7
> Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new function.
```c++
#include "ex76.hpp" // see Exercise 7.6

int main(int argc, char *argv[]) {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
```

## Exercise 7.8
> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?
* Define `read`'s `Sales_data` parameter as plain reference since it's intended to change the `revenue`'s value.
* Define `print`'s `Sales_data` parameter as a reference to `const` since it isn't intended to change any member's value of this object.

## Exercise 7.9
> Add operations to read and print `Person` objects to the code you wrote for [Exercise 7.5](#exercise-75).
```c++
struct Person {
    std::string name;
    std::string address;

    auto getName() const -> const std::string& { return name; }
    auto getAddress() const -> const std::string& { return address; }
};

std::istream& read(std::istream &is, Person &person) {
    return is >> person.name >> person.address;
}

std::ostream& print(std::ostream &os, const Person &person) {
    return os << person.getName() << " " << person.getAddress();
}
```

## Exercise 7.10
> What does the condition in the following `if` statement do?
```c++
if(read(read(cin, data1), data2))
```
we can try to divide it like that:
```c++
std::istream &firstStep = read(cin, data1);
sdt::istream &secondStep = read(firstStep, data2);
if (secondStep)
```
the condition of the `if` statement would read two `Sales_data` object at one time.

## Exercise 7.11
> Add constructors to your `Sales_data` class and write a program to use each of the constructors.
```c++
#include <iostream>
struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream &is);
    
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = .0;
};

// nonmember functions.
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

// member functions.
Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main(int argc, char *argv[]) {
    Sales_data item1;
    print(std::cout, item1) << std::endl;
    
    Sales_data item2("0-201-78345-X");
    print(std::cout, item2) << std::endl;
    
    Sales_data item3("0-201-78345-X", 3, 20.0);
    print(std::cout, item3) << std::endl;
    
    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;
    
    return 0;
}
```

## Exercise 7.12
> Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.
```c++
#include <iostream>
struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream &is) { read(is, *this); }
    
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = .0;
};

// nonmember functions.
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

// member functions.
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## Exercise 7.13
> Rewrite the below program to use the `istream` constructor.
```c++
Sales_data total;
if (read(cin, total)) {
    Sales_data trans;
    while (read(cin, trans)) {
        if (total.isbn() == trans.isbn())
            total.combine(trans);
        else {
            print(cout, total) << endl;
            total = trans;
        }
    }
    print(cout, total) << endl;
} else {
    cerr << "No data?!" << endl;
}
```
The rewrote one is as below:
```c++
Sales_data total(cin);
if (!total.isbn().empty()) {
    istream &is = cin;
    while (is) {
        Sales_data trans(is);
        if (!is) break;
        if (total.isbn() == trans.isbn())
            total.combine(trans);
        else {
            print(cout, total) << endl;
            total = trans;
        }
    }
    print(cout, total) << endl;
} else {
    cerr << "No data?!" << endl;
}
```

## Exercise 7.14
> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.
```c++
Sales_data() : bookNo(""), units_sold(0) , revenue(.0) {}
```

## Exercise 7.15
> Add appropriate constructors to your `Person` class.
```c++
struct Person {
    Person() = default;
    Person(const std::string sname, const std::string saddr) : name(sname), address(saddr) {}
    Person(std::istream &is) { read(is, *this); }

    std::string name;
    std::string address;

    auto getName() const -> const std::string& { return name; }
    auto getAddress() const -> const std::string& { return address; }
};

std::istream& read(std::istream &is, Person &person) {
    return is >> person.name >> person.address;
}

std::ostream& print(std::ostream &os, const Person &person) {
    return os << person.getName() << " " << person.getAddress();
}
```

## Exercise 7.16
> What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

There are no restrictions on how often an access specifier may appear.The specified
access level remains in effect until the next access specifier or the end of the class body.

The members which are accessible to all parts of the program should define after a public specifier.

The members which are accessible to the member functions of the class but are not accessible to code that uses the class should define after a private specifier.

## Exercise 7.17
> What, if any, are the differences between using `class` or `struct`?

The only difference between using `class` and using `struct` to define a class is the default access level.

As a matter of programming style, when we define a class intending for all of its members to be `public`, we use `struct`. If we intend to have `private` members, then we use `class`.

## Exercise 7.18
> What is encapsulation? Why is it useful?

**Encapsulation** is the separation of implementation from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)

Important advantages:
- User code cannot inadvertently corrupt the state of an encapsulation object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

## Exercise 7.19
> Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.
* `public`: constructors, `getName()`, `getAddress()`.
* `private`: `name`, `address`.

the interface should be defined as public, the data shouldn't expose to outside of the class.

## Exercise 7.20
> When are friends useful? Discuss the pros and cons of using friends.

`friend` is a mechanism by which a class grants access to its non-public members. They have the same rights as members.

**Pros**:
- the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
- you can access all the non-public members conveniently.
- sometimes, more readable to the users of class.

**Cons**:
- lessens encapsulation and therefore maintainability.
- code verbosity, declarations inside the class, outside the class.

## Exercise 7.21
> Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.
```c++
#include <iostream>
class Sales_data {
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

    public:
        Sales_data() = default;
        Sales_data(const std::string &s) : bookNo(s) {}
        Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
        Sales_data(std::istream &is) { read(is, *this); }
        
        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = .0;
};

// nonmember functions.
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// member functions.
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

## Exercise 7.22
> Update your `Person` class to hide its implementation.
```c++
#include <iostream>
class Person {
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);

    public:
        Person() = default;
        Person(const std::string sname, const std::string saddr) : name(sname), address(saddr) {}
        Person(std::istream &is) { read(is, *this); }

        auto getName() const -> const std::string& { return name; }
        auto getAddress() const -> const std::string& { return address; }

    private:
        std::string name;
        std::string address;
};

std::istream& read(std::istream &is, Person &person) {
    return is >> person.name >> person.address;
}

std::ostream& print(std::ostream &os, const Person &person) {
    return os << person.getName() << " " << person.getAddress();
}
```

## Exercise 7.23
> Write your own version of the `Screen` class.
```c++
class Screen {
    private:
        using pos = std::string::size_type;
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;

    public:
        Screen() = default;
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
};
```

## Exercise 7.24
> Give your `Screen` class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.
```c++
class Screen {
    private:
        using pos = std::string::size_type;
        pos cursor = 0;
        pos height = 0, width = 0;
        std::string contents;
    
    public:
        Screen() = default; // 1
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {} // 3

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
};
```

## Exercise 7.25
> Can `Screen` safely rely on the default versions of copy and assignment? If so, why? If not, why not?

The class below can rely on it.
* In particular, the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves.
* Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have `vector` or `string` members.

Hence the class below which used only built-in type and `string`s can rely on the default version of copy and assignment.

## Exercise 7.26
> Define `Sales_data::avg_price` as an `inline` function.
```c++
#include <iostream>
class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

    public:
        Sales_data() = default;
        Sales_data(const std::string &s) : bookNo(s) {}
        Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
        Sales_data(std::istream &is) { read(is, *this); }

        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

        inline double avg_price() const;
};

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// friend functions
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
```

## Exercise 7.27
> Add the `move`, `set`, and `display` operations to your version of `Screen`. Test your class by executing the following code:
```c++
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

The class define as follow:
```c++
class Screen {
    private:
        using pos = std::string::size_type;
        pos cursor = 0, height = 0, width = 0;
        std::string contents;

        void do_display(std::ostream &os) const { os << contents; }
    
    public:
        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
        inline Screen& move(pos, pos);
        inline Screen& set(char);
        inline Screen& set(pos, pos, char);

        const Screen& display(std::ostream &os) const { do_display(os); return *this; }
};

inline Screen& Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}
```

## Exercise 7.28
> What would happen in the previous exercise if the return type of `move`, `set` and `display` was `Screen` rather than `Screen&`?

The second call to `display` couldn't print `#` among the output, cause the call to `set` would change the **temporary copy**, not myScreen.

## Exercise 7.29
> Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.
```bash
# with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

## Exercise 7.30
> It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

* Pros
    - more explicit
    - less scope for misreading
    - can use the member function parameter which name is same as the member name.

            void setAddr(const std::string &addr) { this->addr = addr; }

* Cons
    - more to read
    - sometimes redundant

            std::string getAddr() const { return this->addr; } // unnecessary

## Exercise 7.31
> Define a pair of classes `X` and `Y`, in which `X` has a pointer to `Y`, and `Y` has an object of type `X`.
```c++
class Y;

class X {
    Y *y = nullptr;  
};

class Y {
    X x;
};
```

## Exercise 7.32
> Define your own versions of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.
```c++
class Screen;

class Window_mgr {
    private:
        std::vector<Screen> screens;

    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        inline void clear(ScreenIndex);
};

class Screen {
    friend void Window_mgr::clear(ScreenIndex);

    private:
        using pos = std::string::size_type;
        pos cursor = 0, height = 0, width = 0;
        std::string contents;

        void do_display(std::ostream &os) const { os << contents; }
    
    public:
        Screen() = default;
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
        inline Screen& move(pos, pos);
        inline Screen& set(char);
        inline Screen& set(pos, pos, char);

        const Screen& display(std::ostream &os) const { do_display(os); return *this; }
};

inline void Window_mgr::clear(ScreenIndex i) {
    if (i >= screens.size()) return ;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}
```
## Exercise 7.33
> What would happen if we gave `Screen` a `size` member defined as follows? Fix any problems you identify.
```c++
pos Screen::size() const {
    return height * width;
}
```

[clang] error: unknown type name 'pos'

fix it:
```c++
Screen::pos Screen::size() const {
    return height * width;
}
```

## Exercise 7.34
> What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

There is an error in

    dummy_fcn(pos height)
               ^
    Unknown type name 'pos'

## Exercise 7.35
> Explain the following code, indicating which definition of `Type` or `initVal` is used for each use of those names. Say how you would fix any errors.
```c++
typedef string Type;
Type initVal(); // use `string`
class Exercise {
    public:
        typedef double Type;
        Type setVal(Type); // use `double`
        Type initVal();    // use `double`
    private:
        int val;
};

Type Exercise::setVal(Type parm) {  // first is `string`, second is `double`
    val = parm + initVal();         // Exercise::initVal()
    return val;
}
```
fix it as below.
```c++
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

and `Exercise::initVal()` should be defined.

## Exercise 7.36
> The following initializer is in error. Identify and fix the problem.
```c++
struct X {
    X (int i, int j) : base(i), rem(base % j) {}
    int rem, base;
};
```
In this case, the constructor initializer makes it appear as if `base` is initialized with `i` and then `base` is used to initialize `rem`. However, `rem` is initialized first. The effect of this initializer is to initialize `rem` with the undefined value of `base`!

fix it as below.
```c++
struct X {
    X (int i, int j) : base(i), rem(i % j) {}
    int base, rem;
};
```

## Exercise 7.37
> Using the version of `Sales_data` from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
```c++
Sales_data first_item(cin);   // use Sales_data(std::istream &is); its value are up to your input.

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## Exercise 7.38
> We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.
```c++
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## Exercise 7.39
> Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

illegal. Because the call of overloaded `Sales_data()` is **ambiguous**.

## Exercise 7.40
> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.
1. `Book`
2. `Date`
3. `Employee`
4. `Vehicle`
5. `Object`
6. `Tree`

Choose `Book`.
```c++
#include <iostream>

class Book {
    public:
        Book(unsigned isbn, const std::string &name, const std::string &author, const std::string &pubdate) : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate) {}

        Book(std::istream &in) {
            in >> isbn_ >> name_ >> author_ >> pubdate_;
        }

    private:
        unsigned isbn_;
        std::string name_;
        std::string author_;
        std::string pubdate_;
};
```

## Exercise 7.41
> Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.
```c++
#include <iostream>
class Sales_data {
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend Sales_data add(const Sales_data&, const Sales_data&);

    public:
        Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) { std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl; }

        Sales_data() : Sales_data("", 0, .0) { std::cout << "Sales_data()" << std::endl; }

        Sales_data(const std::string &s) : Sales_data(s, 0, .0) { std::cout << "Sales_data(const std::string&)" << std::endl; }

        Sales_data(std::istream &is) : Sales_data() {
                std::cout << "Sales_data(std::istream&)" << std::endl; 
                read(is, *this);
            }

        std::string isbn() const { return bookNo; }
        Sales_data& combine(const Sales_data&);

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

        inline double avg_price() const;
};

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// friend functions
std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// Test
int main() {
    using std::cout; using std::endl;
    cout << "1. default way: " << endl;
    cout << "----------------" << endl;
    Sales_data s1;   
    
    cout << "\n2. use std::string as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s2("CPP-Primer-5th");
    
    cout << "\n3. complete parameters: " << endl;
    cout << "----------------" << endl;
    Sales_data s3("CPP-Primer-5th", 3, 25.8);
    
    cout << "\n4. use istream as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s4(std::cin);
    
    return 0;
}
```

## Exercise 7.42
> For the class you wrote for [Exercise 7.40](#exercise-740) in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.
```c++
#include <iostream>

class Book {
    public:
        Book(unsigned isbn, const std::string &name, const std::string &author, const std::string &pubdate) : isbn_(isbn), name_(name), author_(author), pubdate_(pubdate) {}

        Book(std::istream &in) : Book(0, "", "", "") {
            in >> isbn_ >> name_ >> author_ >> pubdate_;
        }

    private:
        unsigned isbn_;
        std::string name_;
        std::string author_;
        std::string pubdate_;
};
```

## Exercise 7.43
> Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.
```c++
class NoDefault {
    public:
        NoDefault(int) {}
};

class C {
    public:
        C() : x(0) {}
    private:
        NoDefault x;
}
```

## Exercise 7.44
> Is the following declaration legal? If not, why not?
```c++
vector<NoDefault> vec(10);
```
illegal, because there are ten elements, each would be default initialized. But no default initializer for the temporary object.

## Exercise 7.45
> What if we defined the `vector` in the previous exercises to hold objects of type `C`?

No problem. Because `C` have the default constructor.

## Exercise 7.46
> Which, if any, of the following statements are untrue? Why?
1. A class must provide at least one constructor.
    + (**untrue**, "The compiler-generated constructor is known as the synthesized default constructor.")
2. A default constructor is a constructor with an empty parameter list.
    + (**untrue**,  A default constructor is a constructor that is used if no initializer is supplied. What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor)
3. If there are no meaningful default values for a class, the class should not provide a default constructor.
    + (**untrue**, the class should provide.)
4. If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.
    + (**untrue**, only if our class does not explicitly define **any constructors**, the compiler will implicitly define the default constructor for us.)

## Exercise 7.47
> Explain whether the `Sales_data` constructor that takes a `string` should be `explicit`. What are the benefits of making the constructor `explicit`? What are the drawbacks?

Whether the conversion of a `string` to `Sales_data` is desired **depends on how we think our users will use the conversion**. In this case, it might be okay. The `string` in `null_book` probably represents a nonexistent ISBN.
* **Benefits:**
    - We can prevent the use of a constructor in a context that requires an implicit conversion by declaring the constructor as `explicit`
    - We can define a constructor which is used only with the direct form of initialization
* **Drawbacks:**
    - The `explicit` keyword is meaningful only on constructors that can be called with a single argument

## Exercise 7.48
> Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions
```c++
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
What happens if the `Sales_data` constructors are `explicit`?

Both are nothing happened.

## Exercise 7.49
> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:
```c++
Sales_data &combine(Sales_data);   // (a) ok
Sales_data &combine(Sales_data&);  // (b) [Error] no matching function for call to  Sales_data::combine(std::string&) (`std::string&` can not convert to `Sales_data` type.) 
Sales_data &combine(const Sales_data&) const; // (c) The trailing const mark can't be put here, as it forbids any mutation on data members. This conflicts with combine's semantics.
```
Some detailed explanation about problem (b): It's wrong. Because `combine`’s parameter is a non-const reference, we can't pass a temporary to that parameter. If `combine`’s parameter is a  reference to const, we can pass a temporary to that parameter. Like this: `Sales_data &combine(const Sales_data&);` Here we call the `Sales_data::combine` member function with a string argument. This call is perfectly legal; the compiler automatically creates a `Sales_data` object from the given string. That newly generated (temporary) `Sales_data` is passed to `combine`. (Also you can read C++ Primer Page 295 (English Edition))

## Exercise 7.50
> Determine whether any of your `Person` class constructors should be `explicit`.
```c++
#include <iostream>
class Person {
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, const Person&);

    public:
        Person() = default;
        Person(const std::string sname, const std::string saddr) : name(sname), address(saddr) {}
        explicit Person(std::istream &is) { read(is, *this); } // Here should be 'explicit'

        auto getName() const -> const std::string& { return name; }
        auto getAddress() const -> const std::string& { return address; }

    private:
        std::string name;
        std::string address;
};

std::istream& read(std::istream &is, Person &person) {
    return is >> person.name >> person.address;
}

std::ostream& print(std::ostream &os, const Person &person) {
    return os << person.getName() << " " << person.getAddress();
}
```

## Exercise 7.51
> Why do you think `vector` defines its single-argument constructor as `explicit`, i.e., `explicit vector(size_type n);`, but `string` does not?

Such as a function like that:
```c++
int getSize(const std::vector<int>&);
```
if vector has not defined its single-argument constructor as explicit. we can use the function like:
```c++
getSize(34);
```
What is this mean? It's very confused.

But the `std::string` is different. In ordinary, we use `std::string` to replace `const char *` (the C language), so when we call a function like that:
```c++
void setYourName(std::string); // declaration.
setYourName("Hello World!");   // ok.
```
it is very natural.

## Exercise 7.52
> Using our first version of `Sales_data` from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.
```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data item = { "978-0590353403", 25, 15.99 };
```
In my opinion, the aim of the problem is **Aggregate Class**. Test-makers think that `Sales_data` is **Aggregate Class**, so `Sales_data` should have no in-class initializers if we want to initialize the data members of an **Aggregate class** by providing a braced list of member initializers:

**FIXED:**
```c++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```

## Exercise 7.53
> Define your own version of `Debug`.
```c++
class Debug {
    public:
        constexpr Debug(bool b = true) : rt(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o) : rt(h), io(i), other(o) {}
        constexpr bool any() { return rt || io || other; }

        void set_rt(bool b) { rt = b; }
        void set_io(bool b) { io = b; }
        void set_other(bool b) { other = b; }
    
    private:
        bool rt;      // runtime error
        bool io;      // I/O error
        bool other;   // the others
};
```

## Exercise 7.54
> Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

in C++11, `constexpr` member functions are implicitly `const`, so that functions begin with `set_`, which will modify data members, cannot be declared as `constexpr`. In C++14, this property no longer holds, so `constexpr` is suitable.

## Exercise 7.55
> Is the `Data` class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

no.

`std::string` is not a literal type, and it can be verified by following codes:

```c++
#include <iostream>

struct Data {
    int ival;
    std::string s;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
```

## Exercise 7.56
> What is a `static` class member?

A `static` class member that is **associated with the class**, rather than with individual objects of the class type. As a result, they are not initialized by class' constructors.

> What are the advantages of `static` members?

Each object can no need to store a common data. And if the data is changed, each object can use the new value.

> How do they differ from ordinary members?
- A `static` data member can have the same type as the class type of which it is a member. (**incomplete type**); A non-`static` data member is restricted to being declared as a pointer or a reference to an object of its class.
- We can use a `static` member **as a default argument**; A non-`static` data member may not be used as a default argument because its value is part of the object of which it is a member.

## Exercise 7.57
> Write your own version of the `Account` class.
```c++
class Account {
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double newRate) { interestRate = newRate; }
        
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static constexpr double todayRate = 42.42;
        static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();
```

## Exercise 7.58
> Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.
```c++
// example.h
class Example {
    public:
        static double rate = 6.5;
        static const int vecSize = 20;
        static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

```c++
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            we may not specify an in-class initializer inside parentheses.
```
Fix it:
```c++
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};
// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```