#ifndef _BINARYQUERY_H
#define _BINARYQUERY_H

#include<string>
using std::string;

#include"query.h"
#include"query_base.h"


class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s){}
	string rep() const
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;
	string opSym;
};

#endif