#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory>
#include "StrVec.h"

using namespace std;
class QueryResult;
class TextQuery
{
	friend QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &in) :sp(new StrVec())
	{
		std::string line;
		int countline = 0;
		while (std::getline(in, line))
		{
			sp->push_back(line);
			std::istringstream stream(line);
			std::string word;
			while (stream >> word)
			{
				word.erase(std::remove_if(word.begin(), word.end(), ispunct),word.end());
				auto &lines = wordline[word];
				if (!lines)
				{
					lines.reset(new set<line_no>());
				}
				lines->insert(countline);
			}
			countline++;
		}
	}

	QueryResult query(const string word)const;
private:
	shared_ptr<StrVec> sp;
	map<string, shared_ptr<set<line_no>>> wordline;
};

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
	friend std::ostream& operator <<(std::ostream &os, const QueryResult &qr);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(string s, shared_ptr<StrVec> sp, shared_ptr<set<line_no>> line) :sought(s), lines(line), file(sp)
	{}
	set<line_no>::iterator begin()
	{
		return lines->begin();
	}

	set<line_no>::iterator end()
	{
		return lines->end();
	}
	shared_ptr<StrVec> get_file()
	{
		return file;
	}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<StrVec> file;
};
#endif