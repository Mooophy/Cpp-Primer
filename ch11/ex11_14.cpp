// @Yue Wang
// Exercise 11.14:
// Extend the map of children to their family name that you wrote for the
// exercises in § 11.2.1 (p. 424) by having the vector store a pair that
// holds a child’s name and birthday.
//
// Exercise 11.7:
// Define a map for which the key is the family’s last name and
// the value is a vector of the children’s names. Write code to
// add new families and to add new children to an existing family.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::ostream; using std::cout; using std::cin; using std::endl; using std::string;
using std::make_pair; using std::pair; using std::vector; using std::map; 

class Families
{
public:
    using Child     = pair<string, string>;
    using Children  = vector<Child>;
    using Data      = map<string, Children>;

    auto add(string const& last_name, string const& first_name, string birthday) -> void
    {
        _data[last_name].push_back(make_pair(first_name, birthday));
    }

    auto print(std::ostream& os) const -> ostream&
    {
        if (_data.empty())
            return os << "No data right now." << endl;

        for (auto const& pair : _data)
        {
            os << pair.first << ":\n" ;
            for (auto const& child : pair.second)
                os << child.first << " " << child.second << endl;
            os << endl;
        }
        return os;
    }

private:
    Data _data;
};

int main()
{
    Families families; 
    string message = "Please enter last name, first name and birthday";
    for (string l, f, b; cout << message << endl, cin >> l >> f >> b; families.add(l, f, b));
    families.print(cout << "Current data:" << endl);

    return 0;
}
