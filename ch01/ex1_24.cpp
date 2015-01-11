/* Exercise 1.24: Test the previous program by giving multiple transactions 
 * representing multiple ISBNs. The records for each
 * ISBN should be grouped together.
 * written by 蓝色寒冰 QQ 3060871692
 */
#include "Sales_item.h"
#include <map>
#include <vector>

using namespace std;

// compare two Sales_item objects with their isbn
// operator< was declared in Sales_item.h, but was not implemented
bool operator<(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

typedef map<Sales_item, vector<Sales_item> > isbn_grouper;
typedef map<Sales_item, vector<Sales_item> >::iterator 
        isbn_grouper_iterator;

isbn_grouper          isbn_group;
Sales_item            item;

void read_item_in()
{
    while(cin >> item) {
        pair<isbn_grouper_iterator, bool> res;
        vector<Sales_item> svec;
        svec.push_back(item);
        res = isbn_group.insert(pair<Sales_item
                                , vector<Sales_item> >(item, svec));
        if(!res.second) 
            res.first->second.push_back(item);
    }
}

void write_item_out()
{
    for(isbn_grouper_iterator igit = isbn_group.begin();
            igit != isbn_group.end(); 
            igit++) {
        cout << "Group of " << igit->first.isbn() 
             << " has " << igit->second.size() << " members:" << endl;
        // Here is a C++11 range-based for and must be compiled by
        // a compiler that suports C++11.
        // Try to modify aitem to any other type, g++ 4.9.2 will give you
        // what type that atiem should be in its error message.
        for(auto aitem  : igit->second)
            cout << aitem << endl;
        cout << endl;
    }
}

int main(int argc, const char *argv[])
{
    read_item_in();
    write_item_out();
    return 0;
}
