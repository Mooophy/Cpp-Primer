//
//	ex13_31
//	Exercise 13.31
// 	Created by Soyn on 21/7/15.
//	Add the vector<HasPtr>, and sort it.
//
#include<vector>
#include<algorithm>
#include "ex13_31.h"

int main(void)
{
    std :: vector< HasPtr> vh;
    std :: string s1("s"), s2("a"),s3("c");
    HasPtr h1(s1),h2(s2),h3(s3);
    vh.push_back(h1);
    vh.push_back(h2);
    vh.push_back(h3);
    sort(vh.begin(), vh.end());
    for( auto e : vh){
        e.show();
    }
    return 0;
}
