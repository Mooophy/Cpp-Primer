// 15.41.cpp : �������̨Ӧ�ó������ڵ㡣

#include "Query.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream file("Alice.txt");
	TextQuery tQuery(file);
	Query q = Query("fiery")&Query("bird") | Query("wind");
	std::cout << q.eval(tQuery);
	system("pause");
	return 0;
}

