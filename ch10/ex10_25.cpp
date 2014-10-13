//solution to exercise 10.25
#include<iostream>
#include <functional>
#include <algorithm>


void wy_biggies_partition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz)
{
    wy_elimdups(vs);

    // sort words by size, but maintain alphabetical order for words of the same size
    std::stable_sort(vs.begin(), vs.end(),
                     [](const std::string &s1, const std::string &s2){return s1.size() < s2.size();});
	
	 //using bind and check size
   auto wc = std::partition(vs.begin(), vs.end(),
                             bind(check_size, std::placeholders::_1, sz));
                                        
    std::for_each(wc, vs.end(), [](const std::string &s)
                                         {std::cout << s;});

}
//check_size function to check size
bool 
check_size(const std::vector<int> &vec, 
			std::string :: size_type sz ){
	return vec.size() >= sz;
}
