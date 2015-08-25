//
//@Author  @PEZY @Yue Wang 
//@Date    Aug. 2014, Jun 2015
//@Brief
// read a sequence of strings from cin and
// store those values in a vector.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> vec;
    for (std::string buffer; std::cin >> buffer; vec.push_back(buffer));

    return 0;
}
