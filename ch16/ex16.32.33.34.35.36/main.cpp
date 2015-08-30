/***************************************************************************
 *  @file       main.cpp
 *  @author     Yue Wang, Mugurell
 *  @date       04  Feb 2014
 *              Aug, 2015
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.32:
// What happens during template argument deduction?
//  The process of determining the template arguments from the function arguments
//  is known as template argument deduction. During template argument deduction,
//  the compiler uses types of the arguments in the call to find the template
//  arguments that generate a version of the function that best matches the given
//  call.
//
// Exercise 16.33:
// Name two type conversions allowed on function arguments involved in template
// argument deduction.
//  • const conversions: A function parameter that is a reference (or pointer)
//  to a const can be passed a reference (or pointer) to a nonconst object
//  (§ 4.11.2, p. 162).
//
//  • Array- or function-to-pointer conversions: If the function parameter is
//  not a reference type, then the normal pointer conversion will be applied
//  to arguments of array or function type. An array argument will be converted
//  to a pointer to its first element. Similarly, a function argument will be
//  converted to a pointer to the function’s type (§ 4.11.2, p. 161).
//
// Exercise 16.34:
// Given only the following code, explain whether each of these calls is legal.
// If so, what is the type of T? If not, why not?
//     template <class T> int compare(const T&, const T&);
//          compare("hi", "world");
//  It didn't complie, as two types are different, the first type being char[3] , second char[6]
//          compare("bye", "dad");
//   the type should be pointer to char i.e. char*
//
// Exercise 16.35:
// Which, if any, of the following calls are errors? If the call is legal, what
// is the type of T? If the call is not legal, what is the problem?
//      template <typename T> T calc(T, int);
//      template <typename T> T fcn(T, T);
//         double d;    float f;    char c;
//         (a) calc(c, 'c');   -- legal, T is a char
//         (b) calc(d, f);     -- legal, T is a double
//         (c) fcn(c, 'c');    -- legal, T is a char
//         (d) fcn(d, f);      -- illegal, arguments d and f are double and float repectively
//
// Exercise 16.36:
// What happens in the following calls:
//         template <typename T> f1(T, T);
//         template <typename T1, typename T2) f2(T1, T2);
//         int i = 0, j = 42, *p1 = &i, *p2 = &j;
//         const int *cp1 = &i, *cp2 = &j;
//             (a) f1(p1, p2);     // f1<int*>(int*, int*)
//             (b) f2(p1, p2);     // f2<int*, int*>(int*, int*)
//             (c) f1(cp1, cp2);   // f1<int const*>(int const*, int const*)
//             (d) f2(cp1, cp2);   // f2<int const*, int const*>(int const*, int const*)
//             (e) f1(p1, cp1);    // deduced conflicting types for parameter 'T'
//             (f) f2(p1, cp1);    // f2<int*, int const*>(int*, int const*)
//

int main()
{
    return 0;
}
