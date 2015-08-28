//
// @author Yue Wang
// @date   01.12.2014
//
// Exercise 10.3:
// Use accumulate to sum the elements in a vector<int>.
//
// Exercise 10.4:
// Assuming v is a vector<double>, what, if anything,
// is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?
//  Check below.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    // Exercise 10.3
    std::vector<int> v = { 1, 2, 3, 4 };
    std::cout << "ex 10.03: " << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;

    // Exercise 10.4
    std::vector<double> vd = { 1.1, 0.5, 3.3 };
    std::cout   << "ex 10.04: "
                << std::accumulate(vd.cbegin(), vd.cend(), 0)
                << std::endl;                        //   ^<-- note here.
    // @attention
    //
    // The ouput is 4 rather than 4.9 as expected.
    // The reason is std::accumulate is a template function. The third parameter is _Tp __init
    // When "0" , an integer, had been specified here, the compiler deduced _Tp as
    // interger.As a result , when the following statments were being excuted :
    //  for (; __first != __last; ++__first)
    //	__init = __init + *__first;
    //  return __init;
    // all calculation would be converted to integer.

    return 0;
}
