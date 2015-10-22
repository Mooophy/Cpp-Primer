// Yue Wang Oct, 2015
//
// Exercise 11.7:
// Define a map for which the key is the family’s last name and
// the value is a vector of the children’s names. Write code to
// add new families and to add new children to an existing family.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using Families = map<string, vector<string>>;

auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);
    return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
