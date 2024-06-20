#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <memory>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include "QueryResult.h"

using std::map;
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ifstream;
using std::shared_ptr;
using std::make_shared;
using std::istringstream;


class TextQuery {
public:
    TextQuery(){}
    TextQuery( const string &fileName);
    QueryResult query( const string &queryWord) const;
private:
    shared_ptr<vector<string>>              linePtr; 
    map<string,shared_ptr<set<size_t>>>     wordMap;

    /*
     * if a word begins or ends in punctuation, erase it.
    */
    static string 
    ErasePunctuation( string &word )
    {
        if ( ispunct( *--word.end()))
            word.erase(--word.end());
        if ( ispunct( *word.begin()))
            word.erase(word.begin());
        return word;
    }
};

TextQuery::TextQuery( const string &fileName )
{
   linePtr = make_shared<vector<string>>();

   ifstream  srcText(fileName); 
   string   line, word;

   size_t  lineNo = 0;
   while ( getline(srcText,line) ){
       linePtr->push_back(line);
       istringstream   tmp(line);
       while ( tmp >> word ){
           word = ErasePunctuation(word);
           if ( wordMap.find(word) == wordMap.end() )       // This is the first time of the word to appear.
                wordMap[word] = make_shared<set<size_t>>(); 
           wordMap[word]->insert({lineNo});
       }
       ++lineNo;
   }
}
inline QueryResult
TextQuery::query( const string &queryWord ) const
{
    auto ret = wordMap.find(queryWord);
    if ( ret == wordMap.end() ){
        static shared_ptr<set<size_t>> noData( new set<size_t> );
        return QueryResult(queryWord,linePtr,noData);
    } else {
        return QueryResult(queryWord,linePtr,ret->second);
    }
}

#endif
