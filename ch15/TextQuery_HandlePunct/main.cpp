#include <iostream>
using std::cout; using std::cin; using std::endl;

#include<fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include"queryresult.h"
#include"textquery.h"
#include"query.h"
#include"andquery.h"
#include"orquery.h"
#include"notquery.h"

int main()
{
    ifstream fin("test.txt");
	TextQuery text(fin);
	Query q = ~Query("Alice");
	auto result = q.eval(text);
	print(cout, result);
	system("pause");
    return 0;
}

