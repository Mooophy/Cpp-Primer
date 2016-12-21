#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using std::endl;
using std::map;
using std::set;
using std::string;
using std::vector;
using std::ostream;
using std::shared_ptr;

class QueryResult {

friend ostream &print(ostream &out, const QueryResult &result);
public:
    using  SrcLinePtr = shared_ptr<vector<string>>;
    using  LineNoSetPtr = shared_ptr<set<size_t>>;
    QueryResult(){}
    QueryResult( const string &s,SrcLinePtr p2, LineNoSetPtr p3) : queryWord(s),line(p2), lineNo(p3) {} 
    set<size_t>::const_iterator begin();
    set<size_t>::const_iterator end();
    SrcLinePtr get_file();
private:
    string             queryWord;
    SrcLinePtr         line;
    LineNoSetPtr       lineNo;
};

inline set<size_t>::const_iterator 
QueryResult::begin()
{
    return  lineNo->begin();
}

inline set<size_t>::const_iterator 
QueryResult::end()
{
    return lineNo->end();
}

inline QueryResult::SrcLinePtr 
QueryResult::get_file()
{
    return line;
}

ostream &
print( ostream &out, const QueryResult &result)
{
    auto queryWord = result.queryWord;
   
    out << queryWord << " occurs " << (result.lineNo)->size() << " times" << endl;
    for ( auto lineNo : *(result.lineNo) ){
        out << '\t' << "(line " << lineNo +1 << ") " << (*(result.line))[lineNo] << endl;
    }
    return out;
}

#endif
