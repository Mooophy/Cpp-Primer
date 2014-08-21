##Exercise2.39
>Compile the following program to see what happens when
you forget the semicolon after a class definition. Remember the message for
future reference.
```cpp
struct Foo { /* empty  */ } // Note: no semicolon
int main()
{
return 0;
}
```

Error message: [Error] expected ';' after struct definition

##Exercise2.40
>Write your own version of the Sales_data class.

just added some your own define. like this:

```cpp
struct Sale_data
{
  std::string bookNo;
  std::string bookName;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double price = 0.0;
  //...
}
```

##Exercise2.41
>Use your Sales_data class to rewrite the exercises in §
1.5.1(p. 22), § 1.5.2(p. 24), and § 1.6(p. 25). For now, you should define
your Sales_data class in the same file as your main function.

####1.5.1

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sale_data book;
  double price;
  std::cin >> book.bookNo >> book.units_sold >> price;
  book.revenue = book.units_sold * price;
  std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

  return 0;
}
```

####1.5.2

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sale_data book1, book2;
  double price1, price2;
  std::cin >> book1.bookNo >> book1.units_sold >> price1;
  std::cin >> book2.bookNo >> book2.units_sold >> price2;
  book1.revenue = book1.units_sold * price1;
  book2.revenue = book2.units_sold * price2;

  if (book1.bookNo == book2.bookNo)
  {
    unsigned totalCnt = book1.units_sold + book2.units_sold;
    double totalRevenue = book1.revenue + book2.revenue;
    std::cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt != 0)
      std::cout << totalRevenue/totalCnt << std::endl;
    else
      std::cout << "(no sales)" << std::endl;

    return 0;
  }
  else
  {
    std::cerr << "Data must refer to same ISBN" << std::endl;
    return -1;  // indicate failure
  }
}
```

####1.6

**so ugly as you see.**

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main()
{
  Sale_data total;
  double totalPrice;
  if (std::cin >> total.bookNo >> total.units_sold >> totalPrice)
  {
    total.revenue = total.units_sold * totalPrice;

    Sale_data trans;
    double transPrice;
    while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice)
    {
      trans.revenue = trans.units_sold * transPrice;

      if (total.bookNo == trans.bookNo)
      {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      }
      else
      {
        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
          std::cout << total.revenue/total.units_sold << std::endl;
        else
          std::cout << "(no sales)" << std::endl;

        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }

    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
    if (total.units_sold != 0)
      std::cout << total.revenue/total.units_sold << std::endl;
    else
      std::cout << "(no sales)" << std::endl;

    return 0;
  }
  else
  {
    std::cerr << "No data?!" << std::endl;
    return -1;  // indicate failure
  }
}
```

##Exercise2.42
>Write your own version of the Sales_data.h header and
use it to rewrite the exercise from § 2.6.2(p. 76)

You can add some function in your header file. Look at [here](https://github.com/pezy/Cpp-Primer/blob/master/ch02/Sales_data.h).

rewrite the exercise:

- 1.5.1. [Code](https://github.com/pezy/Cpp-Primer/blob/master/ch02/ex2.42_1.cpp)
- 1.5.2. [Code](https://github.com/pezy/Cpp-Primer/blob/master/ch02/ex2.42_1.cpp)
- 1.6. [Code](https://github.com/pezy/Cpp-Primer/blob/master/ch02/ex2.42_1.cpp)
