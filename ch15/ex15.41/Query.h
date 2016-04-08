#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include <memory>

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
	virtual Query_base* clone() const = 0;
};


class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string&);
	QueryResult eval(const TextQuery &t)const
	{
		return q->eval(t);
	}

	Query(const Query &base) :q(base.q->clone())
	{}

	Query& operator=(const Query& query)
	{
		if (this != &query)
		{
			Query_base* temp = query.q->clone();
			delete q;
			q = temp;
		}
		return *this;
	}
	virtual ~Query()
	{
		delete q;
		q = nullptr;
	}
	std::string rep()const { return q->rep(); }
private:
	Query(Query_base* query) :q(query->clone()){}
	Query_base* q;
};

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) :query_word(s){}
	QueryResult eval(const TextQuery &t) const override{ return t.query(query_word); }
	std::string rep() const override{ return query_word; }
	WordQuery* clone() const override
	{
		return new WordQuery(*this);
	}
	std::string query_word;
};
inline Query::Query(const std::string &s) : q(new WordQuery(s)){ }

class NotQuery :public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) :query(q){}
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	NotQuery* clone() const override
	{
		return new NotQuery(*this);
	}
	Query query;
};

inline Query operator~(const Query &operand)
{
	return new NotQuery(operand);
}

class BinaryQuery :public Query_base
{
public:
	BinaryQuery(const Query &l, const Query &r, std::string s) :lhs(l), rhs(r), opSym(s){}
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

	Query lhs, rhs;
	std::string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&"){}
	QueryResult eval(const TextQuery&) const;
	AndQuery* clone() const override
	{
		return new AndQuery(*this);
	}
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|"){}
	QueryResult eval(const TextQuery&) const;
	OrQuery* clone() const override
	{
		return new OrQuery(*this);
	}
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}

std::ostream & operator<<(std::ostream &os, const Query &query);
#endif