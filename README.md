##C++ Primer 5 答案
##C++ Primer 5 Answers

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/pezy/Cpp-Primer?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

### Note

- Use `-std=c++11`(optional: `-pedantic -Wall`) flag when compiling.(or you can use Visual Studio 2012+)
- If you found any bug, please [let me know](https://github.com/Mooophy/Cpp-Primer/issues/new), thanks.
- I have downloaded the headers from this book's [web site](http://www.informit.com/store/c-plus-plus-primer-9780321714114) and put them in the `include` folder.
- In order to test the program in an efficient way, I also put the test data file in the `data` folder.

### How to contribute

- Please **fork**([How?](https://help.github.com/articles/fork-a-repo)) this repository first.
- **Commit**([How?](https://help.github.com/articles/create-a-repo#commit-your-first-change)) in your own repository.
- Give me a **pull request**([How?](https://help.github.com/articles/using-pull-requests)).
- Syncing with([How?](https://help.github.com/articles/syncing-a-fork/)) the origin repository. This is very **important** because this repo updates frequently.

### Table of Contents

- [Chapter 1. Getting Started](ch01/README.md)
- Part I: The Basics
  - [Chapter 2. Variables and Basic Types](ch02/README.md)
  - [Chapter 3. Strings, Vectors, and Arrays](ch03/README.md)
  - [Chapter 4. Expressions](ch04/README.md)
  - [Chapter 5. Statements](ch05/README.md)
  - [Chapter 6. Functions](ch06/README.md)
  - [Chapter 7. Classes](ch07/README.md)
- Part II: The C++ Library
  - [Chapter 8. The IO Library](ch08/README.md)
  - [Chapter 9. Sequential Containers](ch09/README.md)
  - [Chapter 10. Generic Algorithms](ch10/README.md)
  - [Chapter 11. Associative Containers](ch11/README.md)
  - [Chapter 12. Dynamic Memory](ch12/README.md)
- Part III: Tools for Class Authors
  - [Chapter 13. Copy Control](ch13/README.md)
  - [Chapter 14. Overloaded Operations and Conversions](ch14)
  - [Chapter 15. Object-Oriented Programming](ch15)
  - [Chapter 16. Templates and Generic Programming](ch16)
- Part IV:  Advanced Topics
  - [Chapter 17. Specialized Library Facilities](ch17)
  - [Chapter 18. Tools for Large Programs](ch18)
  - Chapter 19. Specialized Tools and Techniques

### How to use makefile in linux
    
- make all     : compile all the cpp file to automake object file and executable file ;
- make clean   : clean all the object file ;
- make clobber : clean all the object file and executable file !

### Notice for makefile
 
- No matter you are in the root direcotry or in the subdirectory of some chapter , the usage of makefile is the same when you want to compile all the cpp/cc file ;
- But if you only want to compile some files (especially one), you cam use "make XXX(this is the list of your chosen file)".

If you know much about makefile, you can change [makefile](GNU_makefile_template) all by yourself !

### If you speak Chinese

1. [PO在StackOverflow上的习题](http://book.douban.com/review/6500246/)
2. [C++ Primer issues(豆瓣讨论组)](http://www.douban.com/group/532124/)
