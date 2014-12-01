//solution to exercise 10.25
#include<iostream>
#include <functional>
#include <algorithm>
#include<vector>
#include<string>

void wy_elimdups(std::vector<std::string> &vs)
{
	for (auto element : vs)
		std::cout << element
		<< " ";
	std::cout << "\n";
}

//check_size function to check size
bool check_size( const std::string &vs, const std::vector<std::string>::size_type sz)
{
	return vs.size() >= sz;
}

void wy_biggies_partition(std::vector<std::string> &vs, const std::vector<std::string>::size_type sz)
{
	wy_elimdups(vs);

	// sort words by size, but maintain alphabetical order for words of the same size
	std::stable_sort(vs.begin(), vs.end(),
		[](const std::string &s1, const std::string &s2){return s1.size() < s2.size(); });

	//using bind and check size
	auto wc = std::partition(vs.begin(), vs.end(),bind(check_size, std::placeholders::_1,sz));

	std::for_each(vs.begin(),wc , [](const std::string &s)
	{std::cout << s<<" "; });

}

int main()
{
	return 0;
}
